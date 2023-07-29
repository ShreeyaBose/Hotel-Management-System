#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void displayRoomTypes();
int bookRoom();
int getNumberOfNights();
double calculateBill(int rooms, int adults, int nights, int roomType);
double calculateGST(double bill);
double applyDiscount(double bill);
void provideComplimentaryBreakfast(double bill);
void displayFoodMenu();
void orderFood();
void getCustomerDetails(char *name, int *age, long long *aadhaarNumber);
void makePayment(double bill, double gstAmount, double discountAmount, double totalAmount);
void saveData(char *name, int age, long long aadhaarNumber, int rooms, int adults, int nights, int roomType, double bill, double gstAmount, double discountAmount, double totalAmount, char modeOfPay, long accountNumber, int pin);

int main() {
    int adults, rooms, nights, roomType;
    double bill, gstAmount, discountAmount, totalAmount;
    char modeOfPay;
    long accountNumber;
    int pin;
    char name[100];
    int age;
    long long aadhaarNumber;

    displayRoomTypes();
    printf("Enter number of rooms:");
    scanf("%d",&rooms);
    printf("Enter the number of perons: ");
    scanf("%d", &adults);

    nights = getNumberOfNights();
    roomType = bookRoom();
    bill = calculateBill(rooms, adults, nights, roomType);
    gstAmount = calculateGST(bill);
    discountAmount = applyDiscount(bill);
    totalAmount = (bill + gstAmount) - discountAmount;
    provideComplimentaryBreakfast(bill);

    if (bill >= 300) {
        displayFoodMenu();
        orderFood();
        printf("Your order will be served in your room.\n");
    }

    getCustomerDetails(name, &age, &aadhaarNumber);
    printf("Your room is booked.\n");

    printf("Choose mode of payment (O for Online, C for Cash): ");
    scanf(" %c", &modeOfPay);

    if (modeOfPay == 'O') {
        printf("Enter account number: ");
        scanf("%ld", &accountNumber);
        printf("Enter PIN: ");
        scanf("%d", &pin);
        printf("Your account has been accessed.\n");

        makePayment(totalAmount, gstAmount, discountAmount, totalAmount);
        saveData(name, age, aadhaarNumber, rooms, adults, nights, roomType, bill, gstAmount, discountAmount, totalAmount, modeOfPay, accountNumber, pin);
    } else {
    	makePayment(totalAmount, gstAmount, discountAmount, totalAmount);
        printf("Pay the cash at the counter.\n");
        saveData(name, age, aadhaarNumber, rooms, adults, nights, roomType, bill, gstAmount, discountAmount, totalAmount, modeOfPay, 0, 0);
    }

    return 0;
}

// Display the available room types and their prices
void displayRoomTypes() 
{
	printf("  -----------WELCOME TO HOTEL MANAGEMENT SYSTEM---------\n");
    printf("        --------------Room Types----------------\n");
    printf("1. Standard Room - Rs.1500 per night\n");
    printf("2. Deluxe Room - Rs.3500 per night\n");
    printf("3. Suite - Rs.5500 per night\n");
    printf("--------------------------\n");
}

// Take user input for booking a room
int bookRoom() {
    int roomType;
    printf("Enter the room type (1-3): ");
    scanf("%d", &roomType);
    return roomType;
}

// Get the number of nights to stay
int getNumberOfNights() {
    int nights;
    printf("Enter the number of nights to stay: ");
    scanf("%d", &nights);
    return nights;
}

// Calculate the bill amount based on the number of adults, children, nights, and room type
double calculateBill(int rooms, int adults, int nights, int roomType) {
    double price = 0;
    switch (roomType) {
        case 1:
            price = 1500.0;
            break;
        case 2:
            price = 3500.0;
            break;
        case 3:
            price = 5500.0;
            break;
        default:
            printf("Invalid room type.\n");
            exit(1);
    }

    double bill = (price * rooms + (price * adults * 0.5)) * nights;
    printf("The cost of stay: %lf\n",bill);
    return bill;
}

// Calculate the GST amount based on the bill amount
double calculateGST(double bill) {
    double gst = 0.18; // 18% GST
    double gstAmount = bill * gst;
    return gstAmount;
}

// Apply a discount based on the bill amount
double applyDiscount(double bill) {
    double discountAmount = 0;
    if (bill >= 4000) {
        discountAmount = bill * 0.1; // 10% discount for bill amount >= $500
    }
    return discountAmount;
}

// Provide complimentary breakfast based on the bill amount
void provideComplimentaryBreakfast(double bill) {
    if (bill >= 3000) {
        printf("Enjoy your complimentary breakfast!\n");
    }
}

// Display the food menu for ordering
void displayFoodMenu() {
    printf("-------- Complimentry Breakfast Available -------\n");
    printf("1. Sandwich and Chocolate Milkshake\n");
    printf("2. Pancakes and Orange Juice\n");
    printf("3. Omelette and Bread Toast\n");
    printf("4. Bread and Butter\n");
    printf("5. Croissant and Black coffee\n");
    printf("6. Oats with banana and Cappuccino\n");
    printf("7. Bagel and coffee\n");
    printf("-------------------------------------------------\n");
}

// Order food from the menu
void orderFood() {
    int choice, quantity;
    do {
        printf("Select the food item (1-7, 0 to exit): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("You ordered %d Sandwiches and chocolate milkshake.\n", quantity);
                break;
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("You ordered %d Pancakes and orange juice.\n", quantity);
                break;
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("You ordered %d Omelette and bread toast.\n", quantity);
                break;
            case 4:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("You ordered %d Bread an butter\n", quantity);
                break;
            case 5:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("You ordered %d Corrisant and black coffee.\n", quantity);
                break;
            case 6:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("You ordered %d Oats with banana and cappuccino.\n", quantity);
                break;
            case 7:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("You ordered %d Bagel and coffee.\n", quantity);
                break;
			case 0:
                printf("Exiting food ordering.\n");
                break;
            default:
                printf("Invalid food item.\n");
                break;
        }
    } while (choice != 0);
}

// Get customer details such as name, age, and Aadhaar number
void getCustomerDetails(char *name, int *age, long long *aadhaarNumber) {
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", age);
    printf("Enter your Aadhaar number: ");
    scanf("%lld", aadhaarNumber);
}

// Process the payment and display the details
void makePayment(double bill, double gstAmount, double discountAmount, double totalAmount) 
{
    printf("GST amount: Rs.%.2f\n", gstAmount);
    printf("Discount amount: Rs.%.2f\n", discountAmount);
    printf("Total amount to pay: Rs.%.2f\n", totalAmount);
}

// Save the booking and payment data to a text file
void saveData(char *name, int age, long long aadhaarNumber, int rooms, int adults, int nights, int roomType, double bill, double gstAmount, double discountAmount, double totalAmount, char modeOfPay, long accountNumber, int pin) {
    FILE *file = fopen("booking_data.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fprintf(file,"\n");
    fprintf(file, "Booking Details:\n");
    fprintf(file, "----------------\n");
    fprintf(file, "Name: %s\n", name);
    fprintf(file, "Age: %d\n", age);
    fprintf(file, "Aadhaar Number: %lld\n", aadhaarNumber);
    fprintf(file, "Number of Rooms: %d\n", rooms);
    fprintf(file, "Number of Persons: %d\n", adults);
    fprintf(file, "Number of Nights: %d\n", nights);
    fprintf(file, "Room Type: %d\n", roomType);
    fprintf(file, "Bill Amount: Rs.%.2f\n", bill);
    fprintf(file, "GST Amount: Rs.%.2f\n", gstAmount);
    fprintf(file, "Discount Amount: Rs.%.2f\n", discountAmount);
    fprintf(file, "Total Amount to Pay: Rs.%.2f\n", totalAmount);
    fprintf(file, "Mode of Payment: %c\n", modeOfPay);

    if (modeOfPay == 'O') {
        fprintf(file, "Account Number: %ld\n", accountNumber);
        fprintf(file, "PIN: %d\n", pin);
    }

    fprintf(file,"\n");
    fclose(file);
    printf("Enjoy your Stay!!!\n");
    printf("Booking data saved successfully.\n");
}
