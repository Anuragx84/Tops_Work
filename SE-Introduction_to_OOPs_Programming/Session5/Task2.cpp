/*2.Build two classes, InstagramUploader and YouTubeUploader, each with a method uploadContent(). 
Both should extend a base class SocialMediaUploader and override uploadContent() to print a message 
showing how uploading works differently for Instagram and YouTube.*/

#include<iostream>
using namespace std;

class SocialMediaUploader{
	public : 
	virtual void uploadContent(){
		cout<<"Social media content uploading...."<<endl;
	}
};

class InstagramUploader : public SocialMediaUploader{
	public : 
	void uploadContent() override
	{
		cout<<"Insatagram content uploader...."<<endl;
	}
};

class YouTubeUploader : public SocialMediaUploader{
	public : 
	void uploadContent() override
	{
		cout<<"Youtube content uploader...."<<endl;
	}
};

int main(){
	SocialMediaUploader sm;
	sm.uploadContent();
	
	InstagramUploader ig;
	ig.uploadContent();
	
	YouTubeUploader yt;
	yt.uploadContent();
	return 0;
}
