#include <iostream>
#include <vector>

using namespace std;

class Task {
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
string Task::getID() const{
	return id;
}

void Task::addTask() {

	cout << "\nEnter Task ID: ";
	cin >> id;
	cout << "\nEnter Task Name: ";
	cin >> task_name;
	cout << "\nEnter Task Description: ";
	cin >> description;
	cout << "\nEnter Task Status: ";
	cin >> status;
	cout << "\nTask Added Successfully!\n";
}

void Task::viewTask() {

	cout << "\nTask ID: " << id << endl;
	cout << "Task Name: " << task_name << endl;
	cout << "Task Description: " << description << endl;
	cout << "Task Status: " << status << endl;

}

void ask() {
	char start = 'y';
	cout << "Do you want to start the Task Manager? (y/n): ";
	cin >> start;
	vector<Task> tasks;

	while (start == 'y') {
		
		int choice;
		cout << "Task Manager\n";
		cout << "============\n";
		cout << "1. Add Task\n";
		cout << "2. View Task\n";
		cout << "3. Update Task\n";
		cout << "4. Delete Task\n";
		cout << "5. Exit\n";
		cout << "============\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			Task task;
			task.addTask();
			tasks.push_back(task);
		}
		else if (choice == 2) {
			for (auto task : tasks) {
				task.viewTask();
			}
		}
		else if (choice == 3) {
			string update_id;
			cout << "Enter ID: ";
			cin >> update_id;
			for (auto& task : tasks) {
				if (task.getID() == update_id) {
					task.addTask();
				}
			}
		}
		else if (choice == 4) {
			string delete_id;
			cout << "Enter ID: ";
			cin >> delete_id;
			for (auto it = tasks.begin(); it != tasks.end(); ++it) {
				if (it->getID() == delete_id) {
					tasks.erase(it);
					cout << "Task Deleted Successfully!\n";
					break;
				}
			}
		}
		else if (choice == 5) {
			break;
		}
		else {
			cout << "No task added yet, or Invalid Input\n";
		}

		cout << "Do you want to continue? (y/n): ";
		cin >> start;
	}

}




int main()
{
	ask();


}
