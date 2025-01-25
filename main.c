#include <stdio.h>
#include <string.h>
#include <threads.h>
#include <time.h>
#define MAX_CUSTOMER 100
#define MAX_ROOMS 100
#ifndef HOTEL_H
#define HOTEL_H

typedef struct {
    int roomNumber;
    int isOccupied;
    char type[8];
    float pricePerNight;
} Room;

typedef struct {
    char name[30];
    char phone[15];
    char email[50];
    int RoomNumber;
    struct tm checkindate;
    struct tm checkoutdate;
} Customer;


void addRoom();
void deleteRoom();
void modifyRoom();
void addCustomer();
void deleteCustomer();
void modifyCustomer();
void bookRoom();
void cancelBooking();
void generateBill();
void displayRoomDetails();
void displayCustomerDetails();

#endif // HOTEL_H
Customer customer[MAX_CUSTOMER];
Room rooms[MAX_ROOMS];
int rooms_count = 0;
int customer_count = 0;
int rooms_index = 0;
int customer_index = 0;


int main (int argc, const char * argv[]) {
    printf(" -------------------------------------------------- \n");
    printf("|                                                   |\n");
    printf("|                                                   |\n");
    printf("|         welcome to saad's hotel managing app      |\n");
    printf("|                                                   |\n");
    printf("|                                                   |\n");
    printf(" -------------------------------------------------- \n");
    int choice;

    do {
        printf(" -------------------------------------------------- \n");
        printf("|                   Functions List :                |\n");
        printf(" -------------------------------------------------- \n");
        printf("<-----1. Add Room----->\n");
        printf("<-----2. Delete Room----->\n");
        printf("<-----3. Modify Room----->\n");
        printf("<-----4. Add Customer----->\n");
        printf("<-----5. Delete Customer----->\n");
        printf("<-----6. Modify Customer----->\n");
        printf("<-----7. Book Room----->\n");
        printf("<-----8. Cancel Booking----->\n");
        printf("<-----9. Generate Bill----->\n");
        printf("<-----10. Display Room Details----->\n");
        printf("<-----11. Display Customer Details----->\n");
        printf("<-----12. Exit----->\n");
        printf("------>Enter your choice: ");
        scanf("%d",&choice);
        getchar();

        switch (choice) {
            case 1: addRoom(); break;
            case 2: deleteRoom(); break;
            case 3: modifyRoom(); break;
            case 4: addCustomer(); break;
            case 5: deleteCustomer(); break;
            case 6: modifyCustomer(); break;
            case 7: bookRoom(); break;
            case 8: cancelBooking(); break;
            case 9: generateBill(); break;
            case 10: displayRoomDetails(); break;
            case 11: displayCustomerDetails(); break;
            case 12: printf("Exiting...\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 12);
    return 0;
}

void addRoom() {
    printf("\n=================Adding rooms...=================\n");
    if (rooms_count >= MAX_ROOMS) {
        printf("Maximum number of rooms reached.\n");
    }
    do{
        printf("Enter room number: ");
        scanf("%d", &rooms[rooms_count].roomNumber);
        getchar();
        if (rooms[rooms_count].roomNumber>MAX_ROOMS)
            printf("Invalid input, there's only 100 rooms. Please enter a correct room number\n");
    }while(rooms[rooms_count].roomNumber>MAX_ROOMS);
    
    printf("Enter room type: ");
    fgets(rooms[rooms_count].type, 8, stdin);
    rooms->type[strcspn(rooms[rooms_count].type, "\n")] = '\0';
    printf("Enter room price: ");
    scanf("%f", &rooms[rooms_count].pricePerNight);
    getchar();
    rooms_count++;
    printf("~~~~~~~~~~Room added succefully~~~~~~~~~~\n\n");
}

void deleteRoom() {
    printf("\n=================Deleting rooms...=================\n");
    printf("Enter room number: ");
    scanf("%d", &rooms_index);
    for (int i=0 ; i<rooms_count ; i++) {
        if (rooms[i].roomNumber == rooms_index) {
            rooms_count--;
            rooms[i].roomNumber = 0;
            rooms[i].isOccupied = 0;
            rooms[i].type[0] = '\0';
        }
    }
    printf("~~~~~~~~~~Room deleted successfully!~~~~~~~~~~\n\n");
}

void modifyRoom() {
    printf("\n=================Modifying rooms...\n=================\n");
    int j=0 ;
    do{
            printf("Enter room number: ");
            scanf("%d", &rooms_index);
            getchar();
            for (j=0 ; j<MAX_ROOMS ; j++){
                if (rooms[j].roomNumber==rooms_index)
                    {
                        break;
                    } 
                }
                if (j==99)
                {
                    printf("Room No : %d not added yet\n", rooms_index);
                }
                
        }while (rooms_index>MAX_ROOMS && j!=100);
    
    for (int i=0 ; i<rooms_count ; i++) {
        if (rooms[i].roomNumber == rooms_index) {
            printf("Enter room type: ");
            fgets(rooms[i].type, 8 , stdin);
            rooms[i].type[strcspn(rooms[i].type,"\n")]='\0';
            printf("Enter room price: ");
            scanf("%f", &rooms[i].pricePerNight);
        }
    }
    printf("~~~~~~~~~~Room modified successfully!~~~~~~~~~~\n\n");
}

void inputDate(struct tm *date) {
    printf("Enter the date (YYYY MM DD): ");
    scanf("%d/%d/%d", &date->tm_year, &date->tm_mon, &date->tm_mday);
    date->tm_year -= 1900;
    date->tm_mon -= 1;
}
int isCheckOutAfterCheckIn(struct tm checkIn, struct tm checkOut) {
    time_t checkInTime = mktime(&checkIn);
    time_t checkOutTime = mktime(&checkOut);

    if (checkOutTime > checkInTime) {
        return 1;
    } else {
        return 0;
    }
}

void addCustomer() {
    if (rooms_count > MAX_CUSTOMER) {
        printf("Too many customers.\n");
    }
    printf("\n=================Adding customers...=================\n");
    printf("Enter customer name: ");
    fgets(customer[customer_count].name, 30, stdin);
    customer[customer_count].name[strcspn(customer[customer_count].name, "\n")] = '\0';
    printf("Enter customer phone: ");
    fgets(customer[customer_count].phone, 15, stdin);
    customer[customer_count].phone[strcspn(customer[customer_count].phone, "\n")] = '\0';;
    printf("Enter customer email: ");
    fgets(customer[customer_count].email, 30, stdin);
    customer[customer_count].email[strcspn(customer[customer_count].email, "\n")] = '\0';;
    customer_count++;
    printf("~~~~~~~~~~Customer added successfully!~~~~~~~~~~\n");
}

void deleteCustomer() {
    printf("\n==============Deleting customers...==============\n");
    int j=0;
    do{
        printf("Enter customer name: ");
        fgets(customer[customer_index].name, 30, stdin);
        customer[customer_index].name[strcspn(customer[customer_index].name, "\n")] = '\0';
        for( j=0 ; j<customer_count ; j++){
            if (strcmp(customer[j].name, customer[customer_index].name)==0)
            {
                break;
            }
        }
        if (j==99)
        {
            printf("There is not a client with such name\n");
        }
        
    }while(j==99);
    for (int i=0 ; i<customer_count ; i++) {
        if (strcmp(customer[i].name, customer[customer_index].name) == 0) {
            customer_count--;
            break;
        }
    }
    printf("~~~~~~~~~~Customer removed successfully!~~~~~~~~~~\n");
}

void modifyCustomer() {
    printf("\n==============Modifying customers...==============\n");
    int j=0;
    do{
        printf("Enter customer name: ");
        fgets(customer[customer_index].name, 30, stdin);
        customer[customer_index].name[strcspn(customer[customer_index].name, "\n")] = '\0';
        for( j=0 ; j<customer_count ; j++){
            if (strcmp(customer[j].name, customer[customer_index].name)==0)
            {
                break;
            }
        }
        if (j==99)
        {
            printf("There is not a client with such name\n");
        }
        
    }while(j==99);
    for (int i=0 ; i<customer_count ; i++) {
        if (strcmp(customer[i].name, customer[customer_index].name) == 0) {
            printf("Enter customer phone: ");
            fgets(customer[i].phone, 15, stdin);
            customer[i].phone[strcspn(customer[i].phone, "\n")] = '\0';
            printf("Enter customer email: ");
            fgets(customer[i].email, 50, stdin);
            customer[i].email[strcspn(customer[i].email, "\n")] = '\0';
            break;
        }
    }
    printf("~~~~~~~~~~Customer modified successfully!~~~~~~~~~~\n\n");
}

void bookRoom() {
    printf("\n==============Booking room...==============\n");
    int j=0;
    do{
        printf("Enter customer name: ");
        fgets(customer[customer_index].name, 30, stdin);
        customer[customer_index].name[strcspn(customer[customer_index].name, "\n")] = '\0';
        for( j=0 ; j<customer_count ; j++){
            if (strcmp(customer[j].name, customer[customer_index].name)==0)
            {
                break;
            }
        }
        if (j==99)
        {
            printf("There is not a client with such name\n");
        }
        
    }while(j==99);
    for (int i=0 ; i<customer_count ; i++) {
        if (strcmp(customer[i].name, customer[customer_index].name) == 0) {
            do{
                printf("Enter room number: ");
                scanf("%d", &rooms_index);
                getchar();
                for (j=0 ; j<MAX_ROOMS ; j++){
                    if (rooms[j].roomNumber==rooms_index)
                    {
                        break;
                    } 
                }
                if (j==99)
                {
                    printf("Room No : %d not added yet\n", rooms_index);
                }
                
            }while (rooms_index>MAX_ROOMS && j!=100);
            
            for (int j=0 ; i<rooms_count ; j++) {
                if (rooms[j].roomNumber == rooms_index) {
                    do {
                         printf("Enter check-in date:\n");
                        inputDate(&customer[i].checkindate);

                        printf("Enter check-out date:\n");
                        inputDate(&customer[i].checkoutdate);
                        if (!isCheckOutAfterCheckIn(customer[customer_index].checkindate, customer[customer_index].checkoutdate))
                            printf("Error: Check-out date must be after the check-in date.\n");
                    }while (!isCheckOutAfterCheckIn(customer[customer_index].checkindate, customer[customer_index].checkoutdate));

                    customer[i].RoomNumber=rooms[j].roomNumber;
                    rooms[j].isOccupied = 1;
                    break;
                }
                if (i==rooms_count-1) {
                    printf("There is no room with that number.\n");
                }
            }
        }
        else{
            printf("There is no customer with that name on the list");
        }
    }
    printf("~~~~~~~~~~Room booked successfully!~~~~~~~~~~\n\n");
}

void cancelBooking() {
    printf("\n==============Cancelling booking...==============\n");
    int j=0;
    do{
        printf("Enter customer name: ");
        fgets(customer[customer_index].name, 30, stdin);
        customer[customer_index].name[strcspn(customer[customer_index].name, "\n")] = '\0';
        for( j=0 ; j<customer_count ; j++){
            if (strcmp(customer[j].name, customer[customer_index].name)==0)
            {
                break;
            }
        }
        if (j==99)
        {
            printf("There is not a client with such name\n");
        }
        
    }while(j==99);
   
    do{
                printf("Enter room number: ");
                scanf("%d", &rooms_index);
                getchar();
                for (j=0 ; j<MAX_ROOMS ; j++){
                    if (rooms[j].roomNumber==rooms_index)
                    {
                        break;
                    } 
                }
                if (j==99)
                {
                    printf("Room No : %d not added yet\n", rooms_index);
                }
                
            }while (rooms_index>MAX_ROOMS && j!=100);
    rooms[rooms_index].isOccupied = 0;
    for (int i = 0 ; i<customer_count ; i++) {
        if (strcmp(customer[i].name, customer[customer_index].name) == 0) {
            customer[i].RoomNumber=0;
            break;
        }
    }
    printf("~~~~~~~~~Booking cancelled successfully~~~~~~~~~\n\n");
}

int daysBetween(const struct tm *start,const struct tm *end) {
    struct tm temp_start = *start;
    struct tm temp_end = *end;

    int start_total_days = temp_start.tm_year * 365 + temp_start.tm_mon * 30 + temp_start.tm_mday;
    int end_total_days = temp_end.tm_year * 365 + temp_end.tm_mon * 30 + temp_end.tm_mday;

    return end_total_days - start_total_days;
}

void generateBill() {
    printf("\n==============Generating bill...==============\n");
    int j=0;
    do{
        printf("Enter customer name: ");
        fgets(customer[customer_index].name, 30, stdin);
        customer[customer_index].name[strcspn(customer[customer_index].name, "\n")] = '\0';
        for( j=0 ; j<customer_count ; j++){
            if (strcmp(customer[j].name, customer[customer_index].name)==0)
            {
                break;
            }
        }
        if (j==99)
        {
            printf("There is not a client with such name\n");
        }
        
    }while(j==99);
    
    for (int i=0 ; i<customer_count ; i++) {
        if (strcmp(customer[i].name, customer[customer_index].name) == 0) {
            int nightsStayed = daysBetween(&customer[i].checkindate, &customer[i].checkoutdate);


            float totalPrice = (float) nightsStayed * rooms[i].pricePerNight ;
            printf("\n~~~~~~~~~~ Bill for %s ~~~~~~~~~~\n", customer[i].name);
            printf("Room Number: %d\n", rooms[i].roomNumber);
            printf("Room Type: %s\n", rooms[i].type);
            printf("Check-in Date: %d-%d-%d\n", customer[i].checkindate.tm_year + 1900, customer[i].checkindate.tm_mon + 1, customer[i].checkindate.tm_mday);
            printf("Check-out Date: %d-%d-%d\n", customer[i].checkoutdate.tm_year + 1900, customer[i].checkoutdate.tm_mon + 1, customer[i].checkoutdate.tm_mday);
            printf("Total Nights Stayed: %d\n", nightsStayed);
            printf("Price per Night: %.2f\n", rooms[i].pricePerNight);
            printf("Total Amount Due: %.2f\n", totalPrice);
            rooms[i].isOccupied = 0;
            printf("~~~~~~~~~~ Thank you for your stay! ~~~~~~~~~~\n\n");
            break;
        }
    }
}

void displayRoomDetails() {
    if (rooms_count == 0)
        printf("\n\n---------------!No room has been added yet!---------------\n\n\n");
    for (int i=0 ; i<rooms_count ; i++) {
        printf("==============================\n");
        printf("Room Number: %d\n", rooms[i].roomNumber);
        printf("Room Type: %s\n", rooms[i].type);
        printf("Room price: %.2f\n", rooms[i].pricePerNight);
        if (rooms[i].isOccupied)
            printf("State: occupied\n");
        else
            printf("State: available\n");
        printf("==============================\n");
    }
}

void displayCustomerDetails() {
    if (customer_count == 0)
        printf("\n\n---------------!There isn't any registred customer!---------------\n\n\n");
    for (int i=0 ; i<customer_count ; i++) {
        printf("==============================\n");
        printf("Customer Name: %s\n", customer[i].name);
        printf("Customer Phone: %s\n", customer[i].phone);
        printf("Customer email: %s\n", customer[i].email);
        printf("==============================\n");
    }
}
