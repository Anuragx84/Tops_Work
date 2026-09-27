/*2.Build a class called InstaStory with a protected property storyViews. Create a 
subclass called SponsoredStory that can access and display the storyViews value.*/

#include<iostream>
using namespace std;

class InstaStory{
	protected : 
		int StoryViews;	
};

class SponsoredStory : public InstaStory{
	public : 
		void set(int StoryViews){
			this->StoryViews = StoryViews;
		}
		
		void get(){
			cout<<StoryViews;
		}
};

int main(){
	SponsoredStory story;
	story.set(157);
	cout<<"Accessing base class protected property StoryViews using Sponsored Story object : ";
	story.get();
	return 0;
}

