#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
	int idNum;//unique identifier
	char firstName[20];
	char surName[20];
	int year;
	float monthlyRental;
	char email[50];
	char accomAvailable[20];//type of accommodation: single room, apartment, bungalow, two story
	int roomAvailable;//1-4 and >4
	int pets;//are pets allowed
	int stayDuration;// one day, <3 days, <7 days, >7 days

	struct Node* next;
};

//searching
struct node* find(int target);//find function

//adding & deleting
void insert();//inserts node into the linked list
void deleteAccommodation();//delete an accommodation from the linked list

//displaying
void displayAll();//display all of the nodes
void displaySpecific();//display specific node
void display(struct Node* temp);//display function

//updating & saving
void saveToFile(struct Node* temp);//save the linked list to a file
void loadFromFile();//load data from the file
void updateAccommodation();//allows the admin to update the accommodation details

//Stats
int getTotalRooms();//gets the % of total rooms

int totalNodes = 0;
struct Node* head = NULL;

void main() {

	/*char s[20];
	char n[20];
	char e[20];
	char accom[20];*/


	//populating the linked list manually
	// 
	//The first
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node) * 1);
	totalNodes++;
	newNode->idNum = totalNodes;
	newNode->next = NULL;
	strcpy(newNode->firstName, "amy");
	strcpy(newNode->surName, "McDonagh");
	newNode->year = 42069;
	newNode->monthlyRental = 123456789;
	strcpy(newNode->email, "my123@googlemail.com");
	strcpy(newNode->accomAvailable, "single");
	newNode->roomAvailable = 69;
	newNode->pets = 0;
	newNode->stayDuration = 4;
	head = newNode;

	//The second
	struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node) * 1);
	totalNodes++;
	newNode2->idNum = totalNodes;
	newNode2->next = NULL;
	strcpy(newNode2->firstName, "Mr");
	strcpy(newNode2->surName, "meseeks");
	newNode2->year = 42069;
	newNode2->monthlyRental = 123456789;
	strcpy(newNode2->email, "meseeks@intergalacticmail.everywhere");
	strcpy(newNode2->accomAvailable, "bungalow");
	newNode2->roomAvailable = 2;
	newNode2->pets = 1;
	newNode2->stayDuration = 23;
	head->next = newNode2;

	int menuChoice = 0;

	printf("Enter 1 to add a new accommodation\n");
	printf("Enter 2 to delete an existing accommodation\n");
	printf("Enter 3 to display all accommodation\n");
	printf("Enter 4 to display a specific accommodation\n");
	printf("Enter 5 to update an existing accommodation\n");
	printf("Enter 6 to save all accommodations to a file\n");
	printf("Enter 7 to get the percentage of each room that is available\n");
	scanf("%d", &menuChoice);

	while (menuChoice != -1) {
		if (menuChoice == 1) {//add an accommodation
			insert();
		}
		else if (menuChoice == 2) {//delete an accommodation
			deleteAccommodation();
		}
		else if (menuChoice == 3) {//display all accommodation
			displayAll();
		}
		else if (menuChoice == 4) {//display specific accommodation
			displaySpecific();
		}
		else if (menuChoice == 5) {//update an accommodation
			updateAccommodation();
		}
		else if (menuChoice == 6) {//save to file
			saveToFile(totalNodes);
		}
		else if (menuChoice == 7) {
			getTotalRooms();
		}
		else if (menuChoice != -1) {
			printf("The value you have entered is incorrect, please try again!\n");
			break;
		}

		printf("\n\nEnter 1 to add a new accommodation\n");
		printf("Enter 2 to delete an existing accommodation\n");
		printf("Enter 3 to display all accommodation\n");
		printf("Enter 4 to display a specific accommodation\n");
		printf("Enter 5 to update an existing accommodation\n");
		printf("Enter 6 to save all accommodations to a file\n");
		scanf("%d", &menuChoice);
	}
}

void insert() {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node) * 1);
	totalNodes++;
	newNode->idNum = totalNodes;
	newNode->next = NULL;

	printf("\nPlease enter the First Name:\n");
	scanf("%s", newNode->firstName);

	printf("Please enter the Sirname:\n");
	scanf("%s", newNode->surName);

	printf("Please enter the year it was built:\n");
	scanf("%d", &newNode->year);

	printf("Please enter the monthly rental income:\n");
	scanf("%f", &newNode->monthlyRental);

	printf("Please enter the email:\n");
	scanf("%s", newNode->email);

	printf("Please enter the type of accommodation:\n");
	scanf("%s", &newNode->accomAvailable);

	printf("please enter how many rooms are available:\n");
	scanf("%d", &newNode->roomAvailable);

	printf("Please enter if pets are allowed(1 = yes or 0 = no):\n");
	scanf("%d", &newNode->pets);

	printf("Please enter the duration of the stay:\n\n");
	scanf("%d", &newNode->stayDuration);

	if (head == NULL) {
		head = newNode;
	}
	else {
		struct Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = newNode;
		newNode->next = NULL;
	}

	printf("Accommodation was successfully added!\n");
}

struct node* find(int target) {
	//start from the first link
	struct Node* current = head;

	//if list is empty
	if (head == NULL) {
		return NULL;
	}

	//navigate through list
	while (current->idNum != target) {

		//if it is last node
		if (current->next == NULL) {
			return NULL;
		}
		else {
			//go to next link
			current = current->next;
		}
	}

	//if data found, return the current Link
	return current;
}

void displayAll() {
	struct Node* temp = head;

	while (temp != NULL) {
		display(temp);
		temp = temp->next;
	}
}

void displaySpecific() {
	int id;
	printf("What is the id of the accommodation you would like to find?\n");
	scanf("%d", &id);
	if (id != 0) {
		struct Node* tmp = find(id);
		if (tmp == NULL) {
			printf("\nThat is not an available ID, please try again\n");
		}
		else {
			display(tmp);
		}
	}
}

void display(struct Node* temp) {
	printf("\n\nID Number: %d", temp->idNum);
	printf("\nName: %s %s", temp->firstName, temp->surName);
	printf("\nYear Built: %d", temp->year);
	printf("\nMonthly Rental Income: %.2f", temp->monthlyRental);
	printf("\nEmail: %s", temp->email);
	printf("\nAvailable accommodation: %s", temp->accomAvailable);
	printf("\nRooms Available: %d", temp->roomAvailable);
	printf("\nPets Allowed: %s", temp->pets == 1 ? "YES" : "NO");
	printf("\nDuration of stay: %d", temp->stayDuration);
}

void updateAccommodation() {
	int id;
	printf("What is the id of the accommodation you would like to find?\n");
	scanf("%d", &id);
	if (id != 0) {
		struct Node* tmp = find(id);
		if (tmp == NULL) {
			printf("\nThat is not an available ID, please try again\n");
		}
		else {

			printf("\nPlease enter the First Name:\n");
			scanf("%s", tmp->firstName);

			printf("Please enter the Sirname:\n");
			scanf("%s", tmp->surName);

			printf("Please enter the year it was built:\n");
			scanf("%d", &tmp->year);

			printf("Please enter the monthly rental income:\n");
			scanf("%f", &tmp->monthlyRental);

			printf("Please enter the email:\n");
			scanf("%s", tmp->email);

			printf("Please enter the type of accommodation:\n");
			scanf("%s", &tmp->accomAvailable);

			printf("please enter how many rooms are available:\n");
			scanf("%d", &tmp->roomAvailable);

			printf("Please enter if pets are allowed(1 = yes or 0 = no):\n");
			scanf("%d", &tmp->pets);

			printf("Please enter the duration of the stay:\n\n");
			scanf("%d", &tmp->stayDuration);
		}
		printf("Accommdation was successfully updated!\n");
	}
}

void deleteAccommodation() {
	int key;
	printf("Enter the ID of the accommodation you wish to delete:\n");
	scanf("%d", &key);
	//start from the first link
	struct Node* current = head;
	struct Node* previous = NULL;

	//if list is empty
	if (head == NULL) {
		return NULL;
	}

	//navigate through list
	while (current->idNum != key) {

		//if it is last node
		if (current->next == NULL) {
			return NULL;
		}
		else {
			//store reference to current link
			previous = current;
			//move to next link
			current = current->next;
		}
	}

	//found a match, update the link
	if (current == head) {
		//change first to point to next link
		head = head->next;
	}
	else {
		//bypass the current link
		previous->next = current->next;
	}

	printf("accommodation was successfully deleted!\n");
	return current;
}

void saveToFile() {
	FILE* fp;

	struct Node* temp = head;
	fp = fopen("accommodations.txt", "w");

	if (fp == NULL) {
		printf("Cannot open file!\n");
	}
	else {
		while (temp != NULL) {
			fprintf(fp, "%d|%s|%s|%d|%.2f|%s|%s|%d|%d|%d\n", temp->idNum, temp->firstName, temp->surName, temp->year, temp->monthlyRental, temp->email, temp->accomAvailable, temp->roomAvailable, temp->pets, temp->stayDuration);
			temp = temp->next;
		}
		fclose(fp);
		printf("All Accommodations were saved!\n");
	}
}

int getTotalRooms() {
	int totalRooms = 0;
	int singleRooms = 0;

	struct Node* temp = head;

	while (temp != NULL) {
		totalRooms += temp->roomAvailable;
		temp = temp->next;
	}

	return totalRooms / 100 * singleRooms;
}