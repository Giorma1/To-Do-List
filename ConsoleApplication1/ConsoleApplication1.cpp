#include <iostream>
#include <vector>
#include <string>
using namespace std;

// class task
class Task {
	// class variables/methods
private:
	string id;
public:

	void ask();
	string getID() const;
	void addTask();
	void viewTask();
	string task_name;
    string description;
	string status;

};
// id getter method
string Task::getID() const{
	return id;
}
// task add method, asking user details for task
void Task::addTask() {

	cout << "\nEnter Task ID: ";
	cin >> id;
	cin.ignore();

	cout << "\nEnter Task Name: ";
	getline(cin, task_name);
	cout << "\nEnter Task Description: ";
	getline(cin, description);
	cout << "\nEnter Task Status: ";
	getline(cin, status);
	cout << "\nTask Added Successfully!\n";
}
// view saved tasks details
void Task::viewTask() {

	cout << "\nTask ID: " << id << endl;
	cout << "Task Name: " << task_name << endl;
	cout << "Task Description: " << description << endl;
	cout << "Task Status: " << status << endl;

}
// asking user for input
void ask() {
	char start = 'y';
	cout << "Do you want to start the Task Manager? (y/n): ";
	cin >> start;
	vector<Task> tasks; // vector for saving tasks details, id, name, description, status.

	while (start == 'y') { // while start variable is 'y' keep ask user. if else, stop;
		
		int choice;
		cout << "\nTask Manager\n";
		cout << "============\n";
		cout << "1. Add Task\n";
		cout << "2. View Task\n";
		cout << "3. Update Task\n";
		cout << "4. Delete Task\n";
		cout << "5. Exit\n";
		cout << "============\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) { // if user iputs 1 (add task),   
			Task task; // create Task class object task,
			task.addTask(); // call method addtask() to ask user to enter details of task,
			tasks.push_back(task); // and add details in tasks vector.
		}
		else if (choice == 2) { // if user inputs 2, (View Task)
			for (auto task : tasks) { // creating for each loop to get all details from tasks vector, and show with viewTask() method.
				task.viewTask();
			}
		}
		else if (choice == 3) { // if user inputs 3, (Update Task)
			string update_id; // create variable to get id of task which user wants to update.
			cout << "Enter ID: ";
			cin >> update_id;
			for (auto& task : tasks) { // check with for each loop which id is same as update id, and after id found, call addTask method to replace it.
				if (task.getID() == update_id) {
					task.addTask();
				}
			}
		}
		else if (choice == 4) { // if user inputs 4 (Delete Task)
			string delete_id; // create variable to get id of task which user want to delete.
			cout << "Enter ID: "; 
			cin >> delete_id;
			for (auto it = tasks.begin(); it != tasks.end(); ++it) { // with for loop, "it" is tasks vectors first element index, and until it is not last elements index it++.
				if (it->getID() == delete_id) { // if id in vector equal to delete id (user inputed id), erase tasks element from "it" index.
					tasks.erase(it);
					cout << "Task Deleted Successfully!\n";
					break;
				}
			}
		}
		else if (choice == 5) { // exit
			break;
		}
		else {
			cout << "No task added yet, or Invalid Input\n";
		}

		cout << "\nDo you want to continue? (y/n): "; // asking user if wants to continue.
		cin >> start;
	}

}




int main()
{
	ask();


}
