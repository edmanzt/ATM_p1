#include <stdio.h>

//saeed heydari  404149031
//edman zardosht 404149039

int main() {

    char firstName[20], lastName[20];
    int balance = 0;
    int pin = 1234;
    int isActive = 0;
    int transactions[10];
    int transactionCount = 0;

    int enteredPin, tries;

    // --- bakhsh vorood ramz va control tedad talash ha ---
    for (tries = 0; tries < 3; tries++) {
        printf("Ramz ra vared konid: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) break;
        printf("Ramz eshtebah!\n");
    }

    if (tries == 3) {
        printf("3 bar eshtebah. Barname khateme miabad...\n");
        return 0;
    }

    int choice;
    do {
        // --- bakhsh namayesh menu asli ---
        printf("\n--- Menu ---\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Entekhab shoma: ");
        scanf("%d", &choice);

        // --- bakhsh ijad hesab ---
        if (choice == 1) {
            if (isActive) {
                printf("Hesab ghablan ijad shode!\n");
            } else {
                printf("Nam khod ra vared konid: ");
                scanf("%s", firstName);

                printf("Nam khanevadegi ra vared konid: ");
                scanf("%s", lastName);

                printf("Mojoodi avalie ra vared konid: ");
                scanf("%d", &balance);

                isActive = 1;
                transactionCount = 0;
                printf("Hesab ba movafaghiat ijad shod!\n");
            }
        }

        // --- bakhsh variz ---
        else if (choice == 2) {
            if (!isActive) {
                printf("Hesab faal nist!\n");
            } else {
                int amount;
                printf("Meghdar variz ra vared konid: ");
                scanf("%d", &amount);

                if (amount > 0) {
                    balance += amount;
                    if (transactionCount < 10) {
                        transactions[transactionCount++] = amount;
                    } else {
                        for (int i = 1; i < 10; i++) transactions[i-1] = transactions[i];
                        transactions[9] = amount;
                    }
                    printf("Variz ba movafaghiat anjam shod!\n");
                } else {
                    printf("Meghdar na motabar ast!\n");
                }
            }
        }

        // --- bakhsh bardasht ---
        else if (choice == 3) {
            if (!isActive) {
                printf("Hesab faal nist!\n");
            } else {
                int amount;
                printf("Meghdar bardasht ra vared konid: ");
                scanf("%d", &amount);

                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    if (transactionCount < 10) {
                        transactions[transactionCount++] = -amount;
                    } else {
                        for (int i = 1; i < 10; i++) transactions[i-1] = transactions[i];
                        transactions[9] = -amount;
                    }
                    printf("Bardasht ba movafaghiat anjam shod!\n");
                } else {
                    printf("Meghdar na motabar ya mojoodi kafi nist!\n");
                }
            }
        }

        // --- bakhsh taghir ramz ---
        else if (choice == 4) {
            int oldPin, newPin;
            printf("Ramz feli ra vared konid: ");
            scanf("%d", &oldPin);

            if (oldPin == pin) {
                printf("Ramz jadid ra vared konid: ");
                scanf("%d", &newPin);
                pin = newPin;
                printf("Ramz ba movafaghiat taghir kard!\n");
            } else {
                printf("Ramz eshtebah ast!\n");
            }
        }

        // --- khorooj ---
        else if (choice == 5) {
            printf("Bedrood!\n");
        }

        else {
            printf("Entekhab na motabar!\n");
        }

    } while (choice != 5);

    return 0;
}
