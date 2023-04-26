#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
	int idNum;
	char firstName[20];
	char surName[20];
	int year;
	float monthlyRental;
	char email[50];
	char accomAvailable[20];//type of accommodation: single room, apartment, bungalow, two story
	int roomAvailable;//1-4 and >4
	bool pets;//are pets allowed
	int stayDuration;// one day, <3 days, <7 days, >7 days

	struct node* next;
}AccomodationsT;

AccomodationsT* head = NULL;

//function declarations

void AddNodeData(AccomodationsT** first, int id, char n[20], char s[20], int year, float monthlyRent, char e[50], char accomAvailable[20], int roomAvailable, bool pet, int duration);//adds the node to the linked list
void addAccommodation(AccomodationsT** first);//add an accomodation
struct node* find(int key);//finds the specific accommodation based on the ID
void displayAccommodations(AccomodationsT** first);//both all accomodations and specific ones if chosen
void updateAccommodations(AccomodationsT** first);//allows the admin to update the accommodation details
void deleteAccommodations(AccomodationsT** first, int key);//delete accommodation from the linked list
void generalStats(AccomodationsT** first);//prints general statistics to the screen
void saveToFile(AccomodationsT** first);//print all of the accommodations in the list to a file
void listRental(AccomodationsT** first);//list all accommodations in order of monthly rental

void main() {
	AccomodationsT* currentN;
	AccomodationsT* previousN;

	int menuChoice = 0, key;

	printf("Enter 1 to add a new accommodation:\n");
	printf("Enter 2 to delete an existing accommodation:\n");
	printf("Enter 3 to display an accommodation:\n");
	printf("Enter 4 to update an existing accommodation:\n");
	printf("Enter 5 to list the general stats of an accommodation:\n");
	printf("Enter 6 to list the monthly rental income of an accommodation:\n");
	scanf("%d", &menuChoice);

	while (menuChoice != -1) {
		if (menuChoice == 1) {//add a new accomodation
			addAccommodation(&head);
		}
		else if (menuChoice == 2) {//delete an accomodation
			printf("Please enter the ID of the accommodation you wish to delete:\n");
			scanf("%d", &key);
			AccomodationsT* deleted = find(key);
			if (deleted != NULL) {
				deleteAccommodations(&head, key);
			}
			else {
				printf("No entry with that ID could be found!\n\n");
			}			
		}
		else if (menuChoice == 3) {//display accomodations
			printf("Please enter the ID of the accommodation you are looking for:\n");
			scanf("%d", &key);
			AccomodationsT* found = find(key);
			if (found != NULL) {
				displayAccommodations(head);
			}
			else {
				printf("No entry with that ID could be found!\n\n");
			}
			
		}
		else if (menuChoice == 4) {//update existing accomodation
			updateAccommodations(&head);
		}
		else if (menuChoice == 5) {//display general stats of an accomodation
			generalStats(&head); 
		}
		else if (menuChoice == 6) {//list the monthly rental income of accomodations
			listRental(&head);
		}
		else if (menuChoice != -1) {
			printf("\nYou have entered an invalid option, please try again!\n\n");
		}

		printf("Enter 1 to add a new accommodation:\n");
		printf("Enter 2 to delete an existing accommodation:\n");
		printf("Enter 3 to display an accommodation:\n");
		printf("Enter 4 to update an existing accommodation:\n");
		printf("Enter 5 to list the general stats of an accommodation:\n");
		printf("Enter 6 to list the monthly rental income of an accommodation:\n");
		scanf("%d", &menuChoice);
	}
}

void AddNodeData(AccomodationsT** first, int id, char n[20], char s[20], int year, float monthlyRent, char e[50], char accomAvailable[20], int roomAvailable, bool pet, int duration) {
	AccomodationsT* newNode = (AccomodationsT*)malloc(sizeof(AccomodationsT) * 1);
	newNode->idNum = id;
	strcpy(newNode->firstName, n);
	strcpy(newNode->surName, s);
	strcpy(newNode->email, e);
	newNode->year = year;
	newNode->monthlyRental = monthlyRent;
	strcpy(newNode->accomAvailable, accomAvailable);
	newNode->roomAvailable = roomAvailable;
	newNode->pets = pet;
	newNode->stayDuration = duration;

	newNode->next = *first;
	*first = newNode;
}

void saveToFile(AccomodationsT** first) {

}

void addAccommodation(AccomodationsT** first) {

}

struct node* find(int key) {
	//start from the first link
	AccomodationsT* current = head;

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
			//go to next link
			current = current->next;
		}
	}

	//if data found, return the current Link
	return current;
}

void displayAccommodations(AccomodationsT** first) {
	AccomodationsT* temp;

	temp = first;
	while (temp != NULL) {
		printf("\n\nID Number: %d", temp->idNum);
		printf("\nName: %s %s", temp->firstName, temp->surName);
		printf("\nYear Built: %d", temp->year);
		printf("\nMonthly Rental Income: %.2f", temp->monthlyRental);
		printf("\nEmail: %s", temp->email);
		printf("\nAvailable accommodation: %s", temp->accomAvailable);
		printf("\nRooms Available: %d", temp->roomAvailable);
		printf("\nPets Allowed: %s", temp->pets ? "YES" : "NO");
		printf("\nDuration of stay: %d", temp->stayDuration);

		if (temp == NULL) {
			printf("There is no accommodation data available.\n");
		}
	}
}

void updateAccommodations(AccomodationsT** first) {

}

void deleteAccommodations(AccomodationsT** first, int key) {
	//start from the first link
	AccomodationsT* current = head;
	AccomodationsT* previous = NULL;

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

	return current;
}

void generalStats(AccomodationsT** first) {

}

void listRental(AccomodationsT** first) {

}