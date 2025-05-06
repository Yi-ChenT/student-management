#include <stdio.h>
// Import string.h to use strcmp, strcpy and so on
#include <string.h>

// Declare a constant to store the max lenght of student name
const int maxLengthOfStudentName = 50;
// Declare a constant to store the max number of grades
const int maxNumberOfGrades = 5;
// Declare a constant to store the max number of student
const int maxOfStudent = 30;
// Declare a constant to store the max length of the student name to search
const int maxLengthOfSearchName = 50;
// Declare a constant to store the max length of the student name to modify
const int maxLengthOfModifyStudentName = 50;
// Declare a constatn to store the temporary line of string
const int tempStoreLineOfString = 100;

// Using typedef will make me use struct without the "struct" prefix, only use the data type that I create to declare a variable 
typedef struct {
	// Declare a array to store the student name
	char studentName[maxLengthOfStudentName];
	// Declare a int to store the student ID
	int studentID;
	// Declare a float to store the student's grades
	float studentGrades[maxNumberOfGrades];
	// Declare a float to store the student's average of grades
	float avgOfGrades;
// The self-defined variable is Student
}Student;

// Prototype of addTheStudent
void addTheStudent(Student* studentsData, int* count);
// Prototype of avgCalculation
void avgCalculation(Student* studentData);
// Prototype of searchTheStudent
void searchTheStudent(Student* studentData, int count);
// Prototype of modifyStudentGrades
void modifyStudentGrades(Student* studentData, int count);
// Prototype of saveDataToFile
void saveDataToFile(Student* studentData, int count);
// Prototype of loadDataFromFile
void loadDataFromFile(Student* studentData, int* count);
// Prototype of sortByDescending
void sortByDescending(Student* studentData, int count);
// Prototype of studentInfoDemonstration
void studentInfoDemonstration(Student* studentData, int count);

int main(void) {
	// Declare a variable to store the number of student by using self-defined variable
	Student studentsData[maxOfStudent];
	// Declare a int variable for using to store the number of student that have been read so far
	int count = 0;
	// Declare a int variable for using to store the user input
	int option;
	// Using do-while loop to do a infinited loop and will be stopped only when user to exit the program
	do {
		// Print the word to the screen
		printf("\nStudent Management System\n");
		// Print the word to the screen
		printf("1. Add a Student.\n");
		// Print the word to the screen
		printf("2. Search for a Student by Name.\n");
		// Print the word to the screen
		printf("3. Modify Student's Grades.\n");
		// Print the word to the screen
		printf("4. Display All Students.\n");
		// Print the word to the screen
		printf("5. Save Data to File.\n");
		// Print the word to the screen
		printf("6. Load Data from File.\n");
		// Print the word to the screen
		printf("7. Exit.\n");
		// Print the word to the screen
		printf("Enter your choice: ");
		// Using scanf_s to read the user input
		scanf_s("%d", &option);
		// Using getchar to remove the \n character
		while (getchar() != '\n');
		
		// Using switch to perform the action based on the user's choice
		switch (option) {
			// Add a student
		case 1:
			// Using if statement to check if the maximum number of student is not reached
			if (count < maxOfStudent) {
				// Calling the addTheStudent
				addTheStudent(studentsData, &count);
			}
			// If the maximum number of student are reacheded, inform the user
			else {
				printf("Reach to the maximum number of students.\n");
			}
			break;
			// Search for student by name
		case 2:
			// Calling the searchTheStudent function
			searchTheStudent(studentsData, count);
			break;
			// Modify the student's grades
		case 3:
			// Calling the modifyStudentGrades function
			modifyStudentGrades(studentsData, count);
			break;
			// Sort the student's grades by descending and display the student's information
		case 4:
			// Calling the sortByDescending function
			sortByDescending(studentsData, count);
			// Calling the studentInfoDemonstration
			studentInfoDemonstration(studentsData, count);
			break;
			// Save the student data to the file
		case 5:
			// Calling the saveDataToFile function
			saveDataToFile(studentsData, count);
			break;
			// Load the student data from the file
		case 6:
			// Calling the loadDataFromFile function
			loadDataFromFile(studentsData, &count);
			break;
			// Exit the program
		case 7:
			break;
		}
		// Repeat until the user choose to exit
	} while (option != 7);

}

/* FUNCTION:
   addTheStudent
   DESCRIPTION :
   This function is used to add a student to the data
   PARAMETERS :
   Student pointer studentData: Pointer to the array of studentData in the main function
   int pointer count : Used to modify the original value of count in the main function and renew the number of student
   RETURNS :
   No return
*/
void addTheStudent(Student* studentsData, int* count) {
	//  Using if statement to check if the maximum number of student is not reached
	if (*count >= maxOfStudent) {
		// Print the error message
		printf("Error: Cannot add more students\n");
		// Exit the function
		return;
	}
	
	// Pointer to the next available student
	Student* studentInfo = &studentsData[*count];
	// Print the word to the screen
	printf("Enter the student's name: ");
	// Using fgets to read the student's name
	fgets(studentInfo->studentName, sizeof(studentInfo->studentName), stdin);
	// Using if statement to check the \n character and remove it
	if (studentInfo->studentName[strlen(studentInfo->studentName) - 1] == '\n') {
		studentInfo->studentName[strlen(studentInfo->studentName) - 1] = '\0';
	}
	// Print the word to the screen
	printf("Enter the student's ID: ");
	// Using scanf_s to read the student ID
	scanf_s("%d", &studentInfo->studentID);
	// Using getchar to remover the \n character
	while (getchar() != '\n');
	// Print the word to the screen
	printf("Enter the student's grades (5 subjects)\n");
	// Using for loop to traverse and read each grades
	for (int i = 0; i < maxNumberOfGrades; i++) {
		// Print the word and the grade to the screen
		printf("Grade %d: ", i + 1);
		// Using scanf_s to read the grade
		scanf_s("%f", &studentInfo->studentGrades[i]);
	}
	// Using getchar to remove the \n character
	while (getchar() != '\n');
	// Calling the avgCalculation function and calculate the average grade
	avgCalculation(studentInfo);
	// Increment student count
	(*count)++;
}

/* FUNCTION:
   avgCalculation
   DESCRIPTION :
   This function is used to calculate the average grade of student
   PARAMETERS :
   Student pointer studentData: Pointer to the array of studentData in the main function
   RETURNS :
   No return
*/
void avgCalculation(Student *studentData) {
	// Initialize the sum of grades
	float sum = 0;
	// Loop through all students
	for (int i = 0; i < maxNumberOfGrades; i++) {
		// Add each student's grade to the sum
		sum += studentData->studentGrades[i];
	}
	// Calculat and store the average grade
	studentData->avgOfGrades = sum / maxNumberOfGrades;
}

/* FUNCTION:
   searchTheStudent
   DESCRIPTION :
   This function is used to search the student
   PARAMETERS :
   Student pointer studentData: Pointer to the array of studentData in the main function
   int count : Traverse the number of student and represents the number of student currently
   RETURNS :
   No return
*/
void searchTheStudent(Student* studentData, int count) {
	// Using array to store the student name which will be searched
	char searchName[maxLengthOfSearchName];
	// Print the word to the screen
	printf("Enter the student's name to search: ");
	// Using fgets to read the student's name for searching
	fgets(searchName, sizeof(searchName), stdin);
	// Using if statement to check and remove the \n character
	if (searchName[strlen(searchName) - 1] == '\n') {
		searchName[strlen(searchName) - 1] = '\0';
	}
	// Using for loop to traverse all student
	for (int i = 0; i < count; i++) {
		// Using strcmp to check if the student name matches
		if (strcmp((studentData + i)->studentName, searchName) == 0) {
			// Print the word and the student information to the screen
			printf("Student found: %s, ID: %d, Average: %.2f\n", (studentData + i)->studentName, (studentData + i)->studentID, (studentData + i)->avgOfGrades);
			// Exit the function
			return;
		}
	}
	// Print the error message
	printf("Student not found.\n");
}

/* FUNCTION:
   modifyStudentGrades
   DESCRIPTION :
   This function is used to modify the grades of the student
   PARAMETERS :
   Student pointer studentData: Pointer to the array of studentData in the main function
   int count : Represents the number of student currently
   RETURNS :
   No return
*/
void modifyStudentGrades(Student* studentData, int count) {
	// Using array to store the student name
	char modifyStudent[maxLengthOfModifyStudentName];
	// Print the word to the screen
	printf("Enter the student's name to modify grades: ");
	// Using fgets to read the student's name for modifying
	fgets(modifyStudent, sizeof(modifyStudent), stdin);
	// Using if statement to check and remove the \n character
	if (modifyStudent[strlen(modifyStudent) - 1] == '\n') {
		modifyStudent[strlen(modifyStudent) - 1] = '\0';
	}
	// Using for loop to traverse all student
	for (int i = 0; i < count; i++) {
		// Using strcmp to check if the student name matches
		if (strcmp((studentData + i)->studentName, modifyStudent) == 0) {
			// Print the word to the screen
			printf("Enter the new grades for a (5 subjects): \n");
			// Using for loop to read each grade of student
			for (int j = 0; j < maxNumberOfGrades; j++) {
				// Print the word and the grade of student
				printf("Grade %d: ", j + 1);
				// Using scanf_s to read the grade
				scanf_s("%f", &(studentData + i)->studentGrades[j]);
			}
			// Using getchar to remove the \n character
			while (getchar() != '\n');
			// Calling the avgCalculation function
			avgCalculation(&studentData[i]);
			// Print the word to the screen
			printf("Grades updated for a.\n");
			// Exit the function
			return;
		}
	}
	// Print the erro message
	printf("Student not found.\n");
}

/* FUNCTION:
   saveDataToFile
   DESCRIPTION :
   This function is used to save the student data to the file
   PARAMETERS :
   Student pointer studentData: Pointer to the array of studentData in the main function
   int count : Represents the number of student currently
   RETURNS :
   No return
*/
void saveDataToFile(Student* studentData, int count) {
	// Declare a file pointer
	FILE* pFile;
	// Using the safe way to open the students.txt with write mode
	errno_t err = fopen_s(&pFile, "C:\\Users\\Chann\\Downloads\\studentData.txt", "w");
	// If the file cannot be opened, an error message will be displayed and returned.
	if (err != 0) {
		// Print the word to the screen
		printf("Error: Could not open students.txt\n");
		// Exit the function
		return;
	}
	// Using for loop to traverse all student
	for (int i = 0; i < count; i++) {
		// Using fprintf to write the student data to the file
		fprintf(pFile, "Name: %s\nID: %d\nAverage Grades: %.2f\n5 Subjects Grades: %.2f %.2f %.2f %.2f %.2f\n",
			(studentData + i)->studentName, (studentData + i)->studentID, (studentData + i)->avgOfGrades, (studentData + i)->studentGrades[0], (studentData + i)->studentGrades[1], (studentData + i)->studentGrades[2], (studentData + i)->studentGrades[3], (studentData + i)->studentGrades[4]);
	}
	// Close the data safely
	fclose(pFile);
	// Print the word to the screen
	printf("Data saved to students.txt\n"); 
}

/* FUNCTION:
   loadDataFromFile
   DESCRIPTION :
   This function is used to load the student data from the file
   PARAMETERS :
   Student pointer studentData: Pointer to the array of studentData in the main function
   int pointer count : Represents the number of student currently
   RETURNS :
   No return
*/
void loadDataFromFile(Student* studentData, int* count) {
	// Declare a file pointer
	FILE* pFile;
	// Using the safe way to open the students.txt with read mode
	errno_t err = fopen_s(&pFile, "C:\\Users\\Chann\\Downloads\\studentData.txt", "r");
	// If the file cannot be opened, an error message will be displayed and returned.
	if (err != 0) {
		// Print the word to the screen
		printf("Error: File not found\n");
		// Exit the function
		return;
	}
	// Reset the student count
	*count = 0;
	// Using array to store each line of text
	char text[tempStoreLineOfString];
	// Read each line from the file
	while (fgets(text, tempStoreLineOfString, pFile) != NULL && *count < maxOfStudent) {
		// Declare a array to store the student name
		char studentName[maxLengthOfStudentName];
		// Declare a int to store the student ID
		int studentID;
		// Declare a float to store the student's grades
		float studentGrades[maxNumberOfGrades];
		// Declare a float to store the student's average grade
		float avgOfGrades;
		// Using sscanf_s function to parse the student's name, ID, average grade, and five subject grades from the string 'text'
		int itemsRead = sscanf_s(text, "Name: %50s\nID: %d\nAverage Grades: %f\n5 Subjects Grades: %f %f %f %f %f\n",
			studentName, (unsigned)sizeof(studentName), &studentID, &avgOfGrades,
			&studentGrades[0], &studentGrades[1], &studentGrades[2], &studentGrades[3], &studentGrades[4]);
		// If all items are read successfully
		if (itemsRead == 8) {
			// Using strcpy_s to copy student's name
			strcpy_s((studentData + *count)->studentName, sizeof((studentData + *count)->studentName), studentName);
			// Set student ID
			(studentData + *count)->studentID = studentID;
			// Using for loop to traverse all student
			for (int i = 0; i < maxNumberOfGrades; i++) {
				// Set student grades
				(studentData + *count)->studentGrades[i] = studentGrades[i];
			}
			// Set average grade
			(studentData + *count)->avgOfGrades = avgOfGrades;
			// Increment student count
			(*count)++;
		}
	}
	// Close the file safely
	fclose(pFile);
	// Print the word to the screen
	printf("Data loaded from students.txt\n");
}

/* FUNCTION:
   sortByDescending
   DESCRIPTION :
   This function is used to sort the student's grades by descending
   PARAMETERS :
   Student pointer studentData: Pointer to the array of studentData in the main function
   int count : Represents the number of student currently
   RETURNS :
   No return
*/
void sortByDescending(Student* studentData, int count) {
	// Outer loop for the number of passes
	for (int x = 0; x < count - 1; x++) {
		// Inner loop for comparing adjacent elements
		for (int y = 0; y < count - x - 1; y++) {
			// If the current average is less than the next
			if ((studentData + y)->avgOfGrades < (studentData + y + 1)->avgOfGrades) {
				// Store the current student in a temporary variable
				Student temp = *(studentData + y);
				// Move the next student to the current position
				*(studentData + y) = *(studentData + y + 1);
				// Move the temporary student to the next position
				*(studentData + y + 1) = temp;
			}
		}
	}
}

/* FUNCTION:
   studentInfoDemonstration
   DESCRIPTION :
   This function is used to display the student's information
   PARAMETERS :
   Student pointer studentData: Pointer to the array of studentData in the main function
   int count : Represents the number of student currently
   RETURNS :
   No return
*/
void studentInfoDemonstration(Student* studentData, int count) {
	// If there are no students to display
	if (count == 0) {
		// Print the word to the screen
		printf("No student to display.\n");
		// Exit the function
		return;
	}
	// Print the word to the screen
	printf("\nStudent List: \n");
	// Print the divider to the screen
	printf("---------------------------------------------------\n");
	// Using for loop to traverse all student
	for (int i = 0; i < count; i++) {
		// Print the word and the student's information to the screen
		printf("Name: %s, ID: %d, Average: %.2f\n", (studentData + i)->studentName, (studentData + i)->studentID, (studentData + i)->avgOfGrades);
	}
	// Print the divider to the screen
	printf("\n---------------------------------------------------\n");
}