/** 
 * LICENSE
 *
 * Copyright (C) Juerg Gutknecht, juerg.gutknecht@students.ffhs.ch
 * 
 * MediatorExample.java is free software copyrighted by Juerg Gutknecht.
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
package ch.juerggutknecht.ffhs.pvaj.mediator.example;

/**
 * A basic mediator pattern example.
 * 
 * Let's assume we have a social media manager. If we post something on one
 * platform, it should be shared on other platforms we have accounts for.
 * 
 * But we don't want to share everything everywhere. If we post something for
 * our friends on Facebook, we want to share it on Google+, but probably not on
 * Twitter and certainly not with our business contacts on LinkedIn and Xing.
 * 
 * We're using the mediator design pattern to centralize communication between
 * our social media platforms.
 * 
 * @author Juerg Gutknecht <juerg.gutknecht@students.ffhs.ch>
 * @version 1.2
 * 
 * Jan 14, 2012
 */
public class MediatorExample {

	public static void main(String[] args) {
		Mediator mediator = new Mediator();

		SocialMediaPlatform facebook = new SocialMediaPlatform("Facebook", mediator);
		SocialMediaPlatform twitter = new SocialMediaPlatform("Twitter", mediator);
		SocialMediaPlatform google = new SocialMediaPlatform("Google+", mediator);
		SocialMediaPlatform linkedIn = new SocialMediaPlatform("LinkedIn", mediator);
		SocialMediaPlatform xing = new SocialMediaPlatform("Xing", mediator);

		mediator.setFacebook(facebook);
		mediator.setTwitter(twitter);
		mediator.setGooglePlus(google);
		mediator.setLinkedIn(linkedIn);
		mediator.setXing(xing);

		SocialMediaPlatform[] platforms = {facebook, twitter, google, linkedIn, xing};

		for (SocialMediaPlatform platform : platforms) {

			platform.post("Posting something on " + platform + "...");

			try {
				System.out.println("");
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}


////////////////////////////////////////////////////////////////////////////////

/**
 * Mediator implementation
 * 
 * @author Juerg Gutknecht <juerg.gutknecht@students.ffhs.ch>
 * @version 1.2
 */
class Mediator {

	private SocialMediaPlatform facebook;
	private SocialMediaPlatform twitter;
	private SocialMediaPlatform google;
	private SocialMediaPlatform linkedIn;
	private SocialMediaPlatform xing;

	public void update(SocialMediaPlatform colleague, Object arg) {

		if (colleague == this.facebook) {
			this.twitter.share(colleague, (String)arg);
			this.google.share(colleague, (String)arg);
		} else if (colleague == this.twitter) {
			this.facebook.share(colleague, (String)arg);
			this.google.share(colleague, (String)arg);
		} else if (colleague == this.google) {
			this.twitter.share(colleague, (String)arg);
			this.facebook.share(colleague, (String)arg);
		} else if (colleague == this.linkedIn) {
			this.xing.share(colleague, (String)arg);
			this.google.share(colleague, (String)arg);
		} else if (colleague == this.xing) {
			this.linkedIn.share(colleague, (String)arg);
			this.google.share(colleague, (String)arg);
		}

	}

	public void setFacebook(SocialMediaPlatform facebook) { this.facebook = facebook; }
	public void setTwitter(SocialMediaPlatform twitter) { this.twitter = twitter; }
	public void setLinkedIn(SocialMediaPlatform linkedIn) { this.linkedIn = linkedIn; }
	public void setXing(SocialMediaPlatform xing) { this.xing = xing; }
	public void setGooglePlus(SocialMediaPlatform google) { this.google = google; }
}


////////////////////////////////////////////////////////////////////////////////

/**
 * A social media platform abstraction. Social media platforms are the
 * colleagues in this mediator pattern example.
 * 
 * @author Juerg Gutknecht <juerg.gutknecht@students.ffhs.ch>
 * @version 1.2
 */
class SocialMediaPlatform {

	public String name = "Generic Social Media Platform";

	private Mediator mediator;

	public SocialMediaPlatform(String name, Mediator mediator) {
		this.name = name;
		this.mediator = mediator;
	}

	public String toString() { return this.name; }

	public void notifyMediator(Object arg) {
		this.mediator.update(this, arg);
	}

	public void post(String status) {
		System.out.printf("[%s] %s\n", this.name, status);
		this.notifyMediator(status);
	}

	public void share(SocialMediaPlatform source, String message) {
		System.out.printf("[%s] From %s: %s\n", this.name, source.name, message);
	}
}


////////////////////////////////////////////////////////////////////////////////
// Life without the mediator pattern:
// 1. Subclasses for all social media platforms
// 2. Tighter coupling, e.g. Facebook needs to know Twitter and Google+ 
// 3. Overriding the post() method to call the share() methods directly

class Facebook extends SocialMediaPlatform {

	private SocialMediaPlatform twitter;
	private SocialMediaPlatform google;

	public Facebook(String name, Mediator mediator) {
		super(name, mediator);
	}

	@Override
	public void post(String status) {
		System.out.printf("[%s] %s\n", this.name, status);
		this.twitter.share(this, status);
		this.google.share(this, status);
	}

	// Setters for Twitter and Google+ here...
}