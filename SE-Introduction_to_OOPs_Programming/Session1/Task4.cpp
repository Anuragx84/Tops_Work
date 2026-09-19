/*4.Build a simple TaskList class/object that stores multiple Task objects and provides addTask(title), 
markTaskDone(index), and showTasks() methods. Demonstrate adding 3 tasks, 
marking one as done, and displaying all tasks with their statuses.*/

#include<iostream>
#include <string>
using namespace std;

class Task{
	public:
		string title;
		bool isDone=false;
};

class TaskList{
	public:
		Task task[50];
		int index = 0;
		
	void addTask(string title){
		task[index].title = title;
		index++;
	}
	
	void markTaskDone(int index){
		task[index].isDone = true;
	}
	
	void showTasks(){
		for(int i=0;i<index;i++){
			cout<<task[i].title<<" : ";
			if(task[i].isDone)
				cout<<"its Done"<<endl;
			else
				cout<<"its not Done"<<endl;
	}
		}
	
};

int main() {
    string title;
    TaskList t1;

    for(int i=0;i<3;i++) {
        cout<<"Enter title of task "<<i+1<<" : ";
        getline(cin,title);
        t1.addTask(title);
    }
    
    t1.markTaskDone(1);
    
    cout << "\nTask List:\n";
    t1.showTasks();

    return 0;
}
