#include<iostream>
#include<fstream>
using namespace std;

/*1.Create a Content class with properties: title, platform, views, and status. 
Write a method to display all details of a Content object.*/
class Content{
	public :
		string title;
		string platform;
		int views;
		string status;
		
	void display(){
	    cout << "Title: " << title << endl;
	    cout << "Platform: " << platform << endl;
	    cout << "Views: " << views << endl;
	    cout << "Status: " << status << endl;
	}
};
/*3.Implement a function to read all content items from content_list.txt 
and display them in a numbered list, showing title and platform for each.*/

void display(Content temp[],int &count){
    int n = 1;
	count = 0;
    ifstream dfile("content_list.txt");

    while(dfile >> temp[count].title
                >> temp[count].platform
                >> temp[count].views
                >> temp[count].status)
    {
        cout << n << ". "
             << temp[count].title << " - "
             << temp[count].platform << endl;

        count++;
        n++;
    }

    dfile.close();
}
int main(){
	/*2.Build a console menu that lets users add new content ideas (title, platform, views, status) 
	and save each entry to a text file named content_list.txt.Hint: Use file handling to append each new content item to the file.</em>*/
	char choice;
	Content ideas[100];
	int i=0;
	display(ideas, i);
	do{
		cout<<"\nA. Add Content";
		cout<<"\nD. Display";
		cout<<"\nU. Update status";
		cout<<"\nX. Delete Content";
	    cout<<"\nE. Exit";
	    cout<<"\nEnter choice: ";
	    cin >> choice;
	    switch(choice) {
	        case 'a':
	        case 'A':{
	        	ofstream file("content_list.txt",ios::app);
	            cout << "Enter Title: ";
	            cin >> ideas[i].title;
	
	            cout << "Enter Platform: ";
	            cin >> ideas[i].platform;
	
	            cout << "Enter Views: ";
	            cin >> ideas[i].views;
	
	            cout << "Enter Status: ";
	            cin >> ideas[i].status;
	
	            file << ideas[i].title<<" "
				     << ideas[i].platform<<" "
	                 << ideas[i].views<<" "
	                 << ideas[i].status << endl;
	
	            cout << "Content added successfully." << endl;
	            i++;
	            file.close();
				break;
				}
			case 'D':
			case 'd':
				display(ideas,i);
				break;
			/*4.Add an option in your console app to let users update the status of any content 
			idea by selecting its number from the displayed list and saving the change back to the file.
			Hint: You will need to read all items, modify the selected one, and overwrite the file.*/	
			case 'U':
			case 'u':
			{
			    int number;
			    cout << "Enter content number: ";
			    cin >> number;			
			    if(number < 1 || number > i)
			    {
			        cout << "Invalid content number." << endl;
			        break;
			    }			
			    string newStatus;			
			    cout << "Enter new status: ";
			    cin >> newStatus;			
			    ideas[number - 1].status = newStatus;			
			    ofstream ufile("content_list.txt");			
			    for(int j = 0; j < i; j++)
			    {
			        ufile << ideas[j].title << " "
			              << ideas[j].platform << " "
			              << ideas[j].views << " "
			              << ideas[j].status << endl;
			    }
			
			    ufile.close();
			
			    cout << "Status updated successfully." << endl;
			
			    break;
			}
			/*5.Add a feature to delete a content item by its number from the list, update the file accordingly, 
			and display the updated list to confirm deletion.*/
			case 'X':
			case 'x':
			{
			    int number;			
			    cout << "Enter content number to delete: ";
			    cin >> number;			
			    if(number < 1 || number > i)
			    {
			        cout << "Invalid content number." << endl;
			        break;
			    }			
			    for(int j=number-1;j<i-1;j++)
			    {
			        ideas[j] = ideas[j + 1];
			    }			
			    i--;			
			    ofstream dfile("content_list.txt");			
			    for(int j = 0; j < i; j++)
			    {
			        dfile << ideas[j].title << " "
			              << ideas[j].platform << " "
			              << ideas[j].views << " "
			              << ideas[j].status << endl;
			    }			
			    dfile.close();			
			    cout << "Content deleted successfully." << endl;			
			    display(ideas, i);			
			    break;
			}
	        case 'e':
	        case 'E':
	            cout << "Exiting..." << endl;
	            break;
	
	        default:
	            cout << "Invalid choice." << endl;
	    }

	} while(choice != 'e' && choice != 'E');
	return 0;
}
