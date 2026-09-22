/*1.Create a base class called SocialMediaUser with properties username and followers, 
and a method displayProfile() that prints the username and follower count.*/

/*2.Build a YouTuber class that inherits from SocialMediaUser and adds a property channelName 
and a method uploadVideo(title) that prints 'Video [title] uploaded to [channelName]'.*/

/*3.Create a Podcaster class that also inherits from SocialMediaUser and adds a property podcastName 
and a method publishEpisode(episodeTitle) that prints 'Episode [episodeTitle] published on [podcastName]'.*/

/*4.Demonstrate multilevel inheritance by creating a class GamingYouTuber that inherits from YouTuber and 
adds a method streamGame(gameName) which prints '[username] is now streaming [gameName] on [channelName]'.*/

/*5.Implement hierarchical inheritance by creating an InstagramInfluencer class that 
inherits from SocialMediaUser and adds a method postStory(storyTitle) which 
prints '[username] posted a new story: [storyTitle]'.Hint: Think about 
how SocialMediaUser is the parent for YouTuber, Podcaster, and InstagramInfluencer.</em>*/

#include<iostream>
using namespace std;

//Task1
class SocialMediaUser{
	public :
		string username;
		int followers;
	
	SocialMediaUser(string username,int followers){
		this->username = username;		
		this->followers = followers;
	}
		
	void displayProfile(){
		cout<<"Username : "<<this->username<<", Followers : "<<this->followers<<endl<<endl;
	}
};

//Task2
class Youtuber : public SocialMediaUser{
	public : 
		string channelName;
		
	Youtuber(string username,int followers,string channelName)
	:
	SocialMediaUser(username,followers)
	{
		this->channelName = channelName;	
	}
	void uploadVideo(string title){
		cout<<"Video ["<<title<<"] uploaded to ["<<channelName<<"]."<<endl<<endl;
	}
};

//Task3
class Podcaster : public SocialMediaUser{
	public :
		string podcastName;
		
	Podcaster(string username,int followers,string podcastName)
	:
	SocialMediaUser(username,followers)
	{
		this->podcastName = podcastName;
	}
	
	void publishEpisode(string episodeTitle){
		cout<<"Episode ["<<episodeTitle<<"] published on ["<<podcastName<<"]. "<<endl<<endl;
	}
};

//Task4
class GamingYoutuber : public Youtuber{
	public :
		
	GamingYoutuber(string username,int followers,string channelName)
	:
	Youtuber( username, followers, channelName){}
		void streamGame(string gameName){
			cout<<"["<<username<<"] is now streaming ["<<gameName<<"] on ["<<channelName<<"]."<<endl<<endl;
		}
};

//Task5
class InstagramInfluencer : public SocialMediaUser{
	public :
	
	InstagramInfluencer(string username,int followers)	:	SocialMediaUser( username, followers){}	
		
	void postStory(string storyTitle){
		cout<<"["<<username<<"] posted a new story: ["<<storyTitle<<"]."<<endl<<endl;
	}
};

int main(){
	GamingYoutuber user("Anurag", 1500, "Anurag Coding");
    user.displayProfile();
    user.uploadVideo("My First C++ Video");
    user.streamGame("Freefire");
    
    Podcaster pod("Anurag", 2000, "Anurag Podcast");
    pod.displayProfile();
    pod.publishEpisode("My First Episode");
    
    InstagramInfluencer iguser("ArjunsinghBhati",2789);
    iguser.postStory("Mausam");
	return 0;
}
