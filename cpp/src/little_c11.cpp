/** 
 * LICENSE
 *
 * Copyright (C) David Daniel (dd), david@daniels.li
 * 
 * little_c11.cpp is free software copyrighted by David Daniel.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * This program comes with ABSOLUTELY NO WARRANTY.
 * This is free software, and you are welcome to redistribute it
 * under certain conditions.
 */

#include	<cstdlib>
#include	<list>
#include	<algorithm>
#include	<functional>
#include	<iostream>

using namespace std;

struct Adder
{
    Adder(int& v) : value_(v) {}

    void operator()(int i)
    { value_ += i; }

    private:
        int& value_;
};

int main (int argc, char** argv)
{
    /* initializer list - c++11 feature, pre c++11 the
     * values needed to be added one by one */
    list<int> some_values = { 1, 4, 6, 3, 8, 90 };

    /* old-school style - need a function object */
    int sum = 0;
    Adder adder(sum);
    for_each (some_values.begin(), some_values.end(), adder);
    cout << "Using a function object of type Adder I get the sum: " << sum << endl;

    /* of course this always worked... */
    sum = 0;
    const list<int>::const_iterator end = some_values.end();
    for (list<int>::const_iterator iter = some_values.begin(); iter != end; ++iter){
        sum += *iter;
    }
    cout << "Using a hand-crafted for-loop with a local end iterator I get the sum: " << sum << endl;

    /* The following needs >= gcc-4.6 (which I don't have already...) */
    // [> but now this is a lot easier <]
    // sum = 0;
    // for (int i : some_values){
        // sum += 1;
    // }
    // cout << "Using the new c++11 featured range-based for loop I get the sum: " << sum << endl;

    /* new style - lamdba forever - this needs >= gcc 4.5... */
    sum = 0;
    for_each (some_values.cbegin(), some_values.cend(), [&sum](int i){ sum += i; });
    cout << "Using a lambda I get the sum: " << sum << endl;

    return EXIT_SUCCESS;
} 
