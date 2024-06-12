// this is an amazing project
#include <iostream>     // io library, std::cin std::cout std::endl
#include <algorithm>    // for std::find
#include <iterator>     // for std::begin and std::end
#include <vector>       // for std::vector
#include <string>

using namespace std;

// Struct of how the file is stored in the table
struct file
{
	char fname[10];
	int start, size, block[10];
}f[10];

// Function to check if block entered already used
// return true if int doesn't exist in the vector
bool lookingFor(int toFind, vector<int> arr)
{
	bool exists = find(begin(arr), end(arr), toFind) == end(arr);
	return exists;
}


// Function to print data, it is moved here from main
void printContent(int number)
{
	system("clear");
	int i, j;
	cout << "\n========================================\n\n";
	cout << "File\tstart\tsize\tblock\n";
	for (i = 0; i < number; i++)
	{
	    cout << f[i].fname << "\t" << f[i].start << "\t" << f[i].size << "\t";
	    for (j = 0; j < f[i].size; j++) 
	    cout << f[i].block[j] << " --> ";
	    cout << f[i].block[j];
	    cout << endl;
	}
	cout << "\n========================================\n\n";

	cout << "Enter to continue~~";
	string temp;
	getline(cin, temp);
	cin.ignore();
}

// does exactly the same with above, with number addition
// to make choosing data number easy
void printContentNumbered(int number)
{
	int i, j;
	cout << "\n========================================\n\n";
	cout << "No.\tFile\tstart\tsize\tblock\n";
	for (i = 0; i < number; i++)
	{
	    cout << i << ". \t" << f[i].fname << "\t" << f[i].start << "\t" << f[i].size << "\t";
	    for (j = 0; j < f[i].size; j++) 
	    cout << f[i].block[j] << " --> ";
	    cout << f[i].block[j];
	    cout << endl;
	}
	cout << "\n========================================\n\n";
}


// function to edit data, reducing and increasing size
// return vector of used blocks in the data
vector<int> editData(int number, int ch, vector<int> used)
{
	int value;
	if(ch == 1)
	{
	    // input number to reduce size
	    cout << "Reduce size, enter number of blocks to be removed: ";
	    cin >> value;
	    while(value > f[number].size)
	    {
	        cout << "Value is bigger than current size. Enter valid value: ";
	        cin >> value;
        }

	    // function that remove blocks from end of data to
	    // the new size
	    for (int i = f[number].size-value; i < f[number].size; i++)
	    {
	        // remove used blocks in 'used' vector, allowing them
	        // for future use.
	        int toRemove = f[number].block[i];
	        used.erase(remove(used.begin(), used.end(), toRemove), used.end());
	        
	        // replace former used block with 0
	        f[number].block[i] = 0;
	    }

        // set new size
	    f[number].size -= value;
	}
	else if(ch == 2)
	{
	    int buffer;
	    bool notExists;

	    // input of new bigger size
	    cout << "Increase size, enter number of new size: ";
	    cin >> value;
	    while (value < f[number].size)
	    {
	        cout << "Value is less than current size. Enter valid value: ";
	        cin >> value;
	    }

	    // insertion of new blocks, does the same method
	    // of checking whether block has been already used or not
	    // as the method in main
	    cout << "Enter new block numbers:\n";
	    for (int i = f[number].size; i < value; i++)
	    {
	        cin >> buffer;
	        notExists = lookingFor(buffer, used);
	        if(notExists)
	        {
	            f[number].block[i] = buffer;
	            used.push_back(buffer);
	        }
	    
	        else 
	        {
	            buffer = 0;
	            while(!buffer)
	            {
	                cout << "Block already used!\nEnter another block: ";
	                cin >> buffer;
	                if(!lookingFor(buffer, used)) buffer = 0;
	            }
        
	            f[number].block[i] = buffer;
	            used.push_back(buffer);
	        }
	    }

	    // set new size
	    f[number].size = value;
	}

	// return vector of used blocks
	return used;
}

int main(int argc, char const *argv[])
{
	int i,j,n,buffer, choice=0;
	bool notExists;

	// Number files to stored
	cout << "Enter number of files: ";
	cin >> n;

	// vector to store already used block numbers
	vector <int> used;
	for (i = 0; i < n; i++)
	{
	    // File details input
	    cout << "Enter file name: ";
	    cin >> f[i].fname;

	    // input block number to buffer instead of
	    // using it immediately
	    cout << "Enter starting block: ";
	    cin >> buffer;

	    // call the function to check whether input is already used or not
	    notExists = lookingFor(buffer, used);
	    if(notExists){
	        f[i].start = buffer;
	        f[i].block[0] = f[i].start;
	        used.push_back(f[i].start);
	    }
	    else
	    {
	        // if block already used, go to this line
	        // will repeatedly ask user input untill
	        // non used int's entered
	        buffer = 0;
	        while(!buffer)
	        {
	            cout << "Block already used!\nEnter another block: ";
	            cin >> buffer;
	            if(!lookingFor(buffer, used)) buffer = 0;
	        }
	        f[i].start = buffer;
	        f[i].block[0] = f[i].start;
	        used.push_back(f[i].start);
	    }

	    cout << "Enter number of blocks: ";
	    cin >> f[i].size;
	    cout << "Enter block numbers: ";
	    for (j = 0; j < f[i].size; j++)
	    {
	        // same procedure as used above 
	        cin >> buffer;
	        notExists = lookingFor(buffer, used);
	        if(notExists)
	        {
	            f[i].block[j] = buffer;
	            used.push_back(buffer);
	        }
	        else 
	        {
	            buffer = 0;
	            while(!buffer)
	            {
	                cout << "Block already used!\nEnter another block: ";
	                cin >> buffer;
	                if(!lookingFor(buffer, used)) buffer = 0;
	            }
	            f[i].block[j] = buffer;
	            used.push_back(buffer);
	        }
	    }
	}

	while (choice != 3)
	{
	    system("clear");
	    cout << "\n1. View file blocks\n2. Edit blocks\n3. Exit\nEnter your choice: ";
	    cin >> choice;
	    switch(choice)
	    {
	        case 1:
	            cout << "\nView file blocks" << endl; 
	            printContent(n);
	            break;
	        case 2:
	            cout << "Edit blocks.\t1. Reduce size\n\t\t2. Increase size\n";
	            int ch;
				int dataNo = 1000;
	            cin >> ch;
	            cout << "Select file number:\n";
	            printContentNumbered(n);
				while( !(dataNo < n) ) 
				{
					cin >> dataNo;
				}

	            // update the used vector
	            used = editData(dataNo,ch,used); 
	            break;
	        default:
	            cout << "Bye~~" << endl;
	            break;
	    }
	}
	return 0;
}
