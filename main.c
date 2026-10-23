#include <stdio.h>
#include <string.h>

char stack[10][10];
int top = -1;

void pushColor(char newColor[]) {
    if (top >= 9) {
        printf("\n[LIMIT] Color history stack is full!\n");
        return;
    }

    top++;
    strcpy(stack[top], newColor);
    printf("\n[SUCCESS] Applied new color: %s\n", stack[top]);
}

void popColor() {
    if (top <= 0) {
        printf("\n[CANNOT UNDO] You are at your base canvas color (%s). No older history available.\n",
               stack[0]);
        return;
    }

    printf("\n[UNDO] Removed ugly color: %s\n", stack[top]);
    top--;
    printf("[RESTORED] Canvas reverted back to previous safe color: %s\n", stack[top]);
}

void currentCanvasColor() {
    if (top == -1) {
        printf("\n[CANVAS EMPTY] No colors applied yet. Transparent layer.\n");
    } else {
        printf("\n[CURRENT SCREEN] Your active background color is: * %s *\n", stack[top]);
    }
}

int main() {
    int choice;
    char inputColor[10];

    pushColor("#FFFFFF");

    while (1) {
        printf("\n===================================\n");
        printf("   DESIGNER'S COLOR PALETTE STACK \n");
        printf("===================================\n");
        printf("1. Try a New Color (Push Hex Code)\n");
        printf("2. Undo Last Color (Pop/Restore Back)\n");
        printf("3. Check Active Screen Color (Peek)\n");
        printf("4. Exit Tool\n");
        printf("Choose an action (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input type. Exiting application safety layer.\n");
            break;
        }

        if (choice == 1) {
            printf("Enter Hex Code (e.g., #008080 or #FF5733): ");
            scanf("%9s", inputColor);
            pushColor(inputColor);
        } else if (choice == 2) {
            popColor();
        } else if (choice == 3) {
            currentCanvasColor();
        } else if (choice == 4) {
            printf("\nClosing tool. Happy Designing!\n");
            break;
        } else {
            printf("\nInvalid entry. Please choose 1, 2, 3, or 4.\n");
        }
    }

    return 0;
}
