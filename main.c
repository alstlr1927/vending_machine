#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

typedef struct beverage //처음 메뉴
{
    char name[20];
} bev;
typedef struct coffee // 커피 메뉴
{
    char cName[20];
    int cPrice;
} cof;
typedef struct tea // 차 메뉴
{
    char tName[20];
    int tPrice;
} t;
typedef struct decaf // 디카페인 메뉴
{
    char dName[30];
    int dPrice;
} def;
typedef struct blended // 블랜디드 메뉴
{
    char bName[30];
    int bPrice;
} blen;
typedef struct dessert // 디저트 메뉴
{
    char desName[20];
    int desPrice;
} des;
typedef struct add // 추가옵션 메뉴
{
    char adName[20];
    int adPrice;
} ad;

void opening();
void printStartMenu(bev bevM[]);                      // 초기 메뉴출력 함수
int selectStartMenu(bev bevM[]);                      // 초기 메뉴 고르는 함수
void printCoffeeMenu(cof cofM[]);                     // 커피 메뉴출력 함수
int selectCoffeeMenu(cof cofM[], ad adM[]);           // 커피 메뉴 고르는 함수
void printTeaMenu(t teaM[]);                          // 차 메뉴출력 함수
int selectTeaMenu(t teaM[], ad adM[]);                // 차 메뉴 고르는 함수
void printDecafMenu(def defM[]);                      // 디카페인 메뉴출력 함수
int selectDecafMenu(def defM[], ad adM[]);            // 디카페인 메뉴 고르는 함수
void printBlendedMenu(blen blenM[]);                  // 블랜디드 메뉴출력 함수
int selectBlendedMenu(blen blenM[], ad adM[]);        // 블랜디드 메뉴 고르는 함수
void printDessertMenu(des desM[]);                    // 디저트 메뉴출력 함수
int selectDessertMenu(des desM[]);                    // 디저트 메뉴 고르는 함수
void printAddOption(ad adM[]);                        // 추가옵션 메뉴출력 함수
void selectAddOption(ad adM[], int *add1, int *add2); // 추가옵션 고르는 함수
int inputMoney();                                     // 결제하는 함수
void ending();

int extendedPrice = 0; // 전역변수 최종금액

int main()
{
    bev bevM[SIZE + 1] = {"Coffee", "Tea", "DECAF Coffee", "Blended", "Dessert"};
    cof cofM[SIZE] = {{"Americano", 2500}, {"Espresso", 1500}, {"Cappuccino", 3500}, {"Cafe Latte", 3500}};
    t teaM[SIZE] = {{"Blacksugar Tea", 3500}, {"Bubble Tea", 3000}, {"Green Tea", 2500}, {"Milk Tea", 3000}};
    def defM[SIZE] = {{"DECAF Latte", 3000}, {"DECAF Americano", 4000}, {"DECAF Macchiato", 4500}, {"DECAF Dolcelatte", 5000}};
    blen blenM[SIZE] = {{"Mango Blended", 5000}, {"Yogurt Blended", 5500}, {"Peach Blended", 5000}, {"Chocolate Blended", 5500}};
    des desM[SIZE] = {{"Cheese Cake", 6500}, {"Mini Scone", 3500}, {"Tiramisu", 5500}, {"Bluberry Bagel", 4500}};
    ad adM[SIZE - 1] = {{"add shot", 500}, {"size up", 1000}, {"nothing", 0}};
    int selectM = 0;
    int yesNo = 0;
    char spaceBar = 0;

    while (1) // 1번 루트
    {
        opening();

        while (1) // 2번 루트
        {
            MENU:
            system("cls");
            selectM = selectStartMenu(bevM);

            if (selectM == -1) // 초기메뉴 선택 함수에서 -1 반환되면 goto 프로그램 종료로
                goto END;
            if (selectM == -2) // 초기메뉴 선택 함수에서 -2 반환되면 2번루트 파괴 결제함수로
                break;

            if (selectM == 1) // if 조건 coffee
            {
                system("cls");
                selectM = selectCoffeeMenu(cofM, adM);

                if (selectM == -1) // 커피메뉴 선택함수에서 -1 반환되면 continue 2번 루트 처음으로
                    continue;
                if (selectM == -2) // 커피메뉴 선택함수에서 -2 반환되면 goto 결제 함수로
                    goto pay;
                printf("Pick More = 1   Payment = 2   : "); // 다른 품목도 고를지 or 결제 할지
                scanf("%d", &yesNo);                        // yesNo ==1  --> 무한반복으로 초기메뉴부터 시작
                if (yesNo == 2)
                    break; // yesNo ==2  --> break 2번 루트 파괴 결제 함수로
            }
            else if (selectM == 2) // if 조건 tea
            {                      // 아래는 과정은 위와 동일
                system("cls");
                selectM = selectTeaMenu(teaM, adM);
                if (selectM == -1)
                    continue;
                if (selectM == -2)
                    goto pay;
                printf("Pick More = 1   Payment = 2   : ");
                scanf("%d", &yesNo);
                if (yesNo == 2)
                    break;
            }
            else if (selectM == 3) // if 조건 decaf
            {                      // 아래는 과정은 위와 동일
                system("cls");
                selectM = selectDecafMenu(defM, adM);
                if (selectM == -1)
                    continue;
                if (selectM == -2)
                    goto pay;
                printf("Pick More = 1   Payment = 2   : ");
                scanf("%d", &yesNo);
                if (yesNo == 2)
                    break;
            }
            else if (selectM == 4) // if 조건 blended
            {                      // 아래는 과정은 위와 동일
                system("cls");
                selectM = selectBlendedMenu(blenM, adM);
                if (selectM == -1)
                    continue;
                if (selectM == -2)
                    goto pay;
                printf("Pick More = 1   Payment = 2   : ");
                scanf("%d", &yesNo);
                if (yesNo == 2)
                    break;
            }
            else if (selectM == 5) // if 조건 dessert
            {                      // 아래는 과정은 위와 동일
                system("cls");
                selectM = selectDessertMenu(desM);
                if (selectM == -1)
                    continue;
                if (selectM == -2)
                    goto pay;
                printf("Pick More = 1   Payment = 2   : ");
                scanf("%d", &yesNo);
                if (yesNo == 2)
                    break;
            }
        }
        pay:
        system("cls");        // goto pay 는 결제함수로 이동
        yesNo = inputMoney(); // yesNo 반환

        if (yesNo == 1) // 아무것도 선택안하고 결제창으로 이동시
            goto MENU;  // 선택에 의해 초기메뉴로 보내거나 프로그램 종료

        END:
        ending(); // goto END 는 프로그램 종료 문구로 이동
    }
    return 0;
}
void opening()
{
    char pressA = 0;

    system("cls");
    printf("============================================\n");
    printf("|           H y u n ' s  C A F E           |\n");
    printf("============================================\n");
    printf("============================================\n");
    printf("|                                          |\n");
    printf("|                                          |\n");
    printf("|                H E L L O                 |\n");
    printf("|                                          |\n");
    printf("|                                          |\n");
    printf("================ Press Enter ===============\n\n");
    system("pause");

    return;
}
void printStartMenu(bev bevM[]) // 처음 메뉴판 매개변수 초기메뉴 구조체
{
    printf("=================================\n");
    printf("<<<<<<<<<Select Beverage>>>>>>>>>\n");
    printf("=================================\n");
    printf(" 1 : %s                    \n", bevM[0].name);
    printf("                               \n");
    printf(" 2 : %s                       \n", bevM[1].name);
    printf("                               \n");
    printf(" 3 : %s              \n", bevM[2].name);
    printf("                               \n");
    printf(" 4 : %s                   \n", bevM[3].name);
    printf("                               \n");
    printf(" 5 : %s                   \n", bevM[4].name);
    printf("=================================\n");
    printf("=================================\n");
    printf(" End of program          >> -1 \n\n");
    printf(" Go to payment           >> -2 \n");
    printf("=================================\n");

    return;
}
int selectStartMenu(bev bevM[]) // 메뉴 고르기
{
    int selectM = 0;

    while (1) // 1번 루트
    {
        printStartMenu(bevM);
        printf("Select Beverage(1 ~ 5) : ");
        scanf("%d", &selectM);
        system("cls");

        if (selectM == -1 || selectM == -2) // 결제 또는 프로그램 종료 결정시 1번 루트 파괴
            break;

        if (selectM > 5 || selectM < 1) // 선택범위 벗어나면 경고후 1번루트 반복
        {
            system("cls");
            printf("==================================\n");
            printf("    Choose again correctly!!    \n");
            printf("==================================\n");
            continue;
        }
        else
            break; // 범위내 선택시 1번루트 파괴
    }
    printf("\n");

    return selectM; // 창 이동을 결정하기 위해 selectM 반환
}
void printCoffeeMenu(cof cofM[]) // 커피 메뉴판
{
    printf("=================================\n");
    printf("<<<<<<<<<<Select Coffee>>>>>>>>>>\n");
    printf("=================================\n");
    printf(" 1 : %s         %dWon \n", cofM[0].cName, cofM[0].cPrice);
    printf("                               \n");
    printf(" 2 : %s          %dWon \n", cofM[1].cName, cofM[1].cPrice);
    printf("                               \n");
    printf(" 3 : %s        %dWon \n", cofM[2].cName, cofM[2].cPrice);
    printf("                               \n");
    printf(" 4 : %s        %dWon \n", cofM[3].cName, cofM[3].cPrice);
    printf("=================================\n");
    printf("=================================\n");
    printf(" Back to Menu            >> -1 \n\n");
    printf(" Go to payment           >> -2 \n");
    printf("=================================\n");

    return;
}
int selectCoffeeMenu(cof cofM[], ad adM[]) // 커피메뉴 고르기 커피, 추가옵션 구조체 사용
{
    int selectM = 0;
    int add1 = 0, add2 = 0; // 추가옵션 변수
    int cups = 0;           // 음료 수량 변수

    while (1) // 1번 루트
    {
        printCoffeeMenu(cofM);
        printf("Select Coffee(1 ~ 4) : ");
        scanf("%d", &selectM);

        if (selectM == -1 || selectM == -2)
            break; // -1 or -2 고를시 1번 루트 파괴

        if (selectM > 4 || selectM < 1)
        {
            system("cls");
            printf("==================================\n");
            printf("    Choose again correctly!!    \n");
            printf("==================================\n");
            continue; // 범위 초과시 1번 루트 반복
        }
        else
        {
            printf("\nHow many cups : "); // 몇잔을 할지 결정
            scanf("%d", &cups);
            system("cls");
            printAddOption(adM);                // 추가옵션 메뉴 출력
            selectAddOption(adM, &add1, &add2); // 추가 옵션 선택 함수  값을 두개 반환 하기 위해 포인터 사용

            extendedPrice += (adM[add1 - 1].adPrice + adM[add2 - 1].adPrice); // 추가옵션 금액 추가
            extendedPrice += (cofM[selectM - 1].cPrice * cups);               // 물품 가격에 수량을 곱해 금액 결정
            break;
        }
    }
    printf("\n");

    return selectM; // 메인 함수 88번줄 조건문에 영향
}
void printTeaMenu(t teaM[]) // 차 메뉴판
{
    printf("=================================\n");
    printf("<<<<<<<<<<<<Select Tea>>>>>>>>>>>\n");
    printf("=================================\n");
    printf(" 1 : %s    %dWon \n", teaM[0].tName, teaM[0].tPrice);
    printf("                               \n");
    printf(" 2 : %s        %dWon \n", teaM[1].tName, teaM[1].tPrice);
    printf("                               \n");
    printf(" 3 : %s         %dWon \n", teaM[2].tName, teaM[2].tPrice);
    printf("                               \n");
    printf(" 4 : %s          %dWon \n", teaM[3].tName, teaM[3].tPrice);
    printf("=================================\n");
    printf("=================================\n");
    printf(" Back to Menu            >> -1 \n");
    printf(" Go to payment           >> -2 \n");
    printf("=================================\n");

    return;
}
int selectTeaMenu(t teaM[], ad adM[]) // 차 메뉴 고르기
{                                     // 커피메뉴 선택 함수와 구조 동일
    int selectM = 0;
    int add1 = 0, add2 = 0;
    int cups = 0;

    while (1)
    {
        printTeaMenu(teaM);
        printf("Select Tea(1 ~ 4) : ");
        scanf("%d", &selectM);

        if (selectM == -1 || selectM == -2)
            break;

        if (selectM > 4 || selectM < 1)
        {
            system("cls");
            printf("==================================\n");
            printf("    Choose again correctly!!    \n");
            printf("==================================\n");
            continue;
        }
        else
        {
            printf("\nHow many cups : ");
            scanf("%d", &cups);
            system("cls");
            printAddOption(adM);
            selectAddOption(adM, &add1, &add2);

            extendedPrice += (adM[add1 - 1].adPrice + adM[add2 - 1].adPrice);
            extendedPrice += (teaM[selectM - 1].tPrice * cups);
            break;
        }
    }
    printf("\n");

    return selectM;
}
void printDecafMenu(def defM[]) // 디카페인 메뉴판
{
    printf("=================================\n");
    printf("<<<<<<<<<<<Select Decaf>>>>>>>>>>\n");
    printf("=================================\n");
    printf(" 1 : %s       %dWon \n", defM[0].dName, defM[0].dPrice);
    printf("                               \n");
    printf(" 2 : %s   %dWon \n", defM[1].dName, defM[1].dPrice);
    printf("                               \n");
    printf(" 3 : %s   %dWon \n", defM[2].dName, defM[2].dPrice);
    printf("                               \n");
    printf(" 4 : %s  %dWon \n", defM[3].dName, defM[3].dPrice);
    printf("=================================\n");
    printf("=================================\n");
    printf(" Back to Menu            >> -1 \n\n");
    printf(" Go to payment           >> -2 \n");
    printf("=================================\n");

    return;
}
int selectDecafMenu(def defM[], ad adM[]) // 디카페인 메뉴 고르기
{                                         // 커피메뉴 선택 함수와 구조 동일
    int selectM = 0;
    int add1 = 0, add2 = 0;
    int cups = 0;

    while (1)
    {
        printDecafMenu(defM);
        printf("Select Decaf(1 ~ 4) : ");
        scanf("%d", &selectM);

        if (selectM == -1 || selectM == -2)
            break;

        if (selectM > 4 || selectM < 1)
        {
            system("cls");
            printf("==================================\n");
            printf("    Choose again correctly!!    \n");
            printf("==================================\n");
            continue;
        }
        else
        {
            printf("\nHow many cups : ");
            scanf("%d", &cups);
            system("cls");
            printAddOption(adM);
            selectAddOption(adM, &add1, &add2);

            extendedPrice += (adM[add1 - 1].adPrice + adM[add2 - 1].adPrice);
            extendedPrice += (defM[selectM - 1].dPrice * cups);
            break;
        }
    }
    printf("\n");

    return selectM;
}
void printBlendedMenu(blen blenM[]) // 블랜디드 메뉴
{
    printf("=================================\n");
    printf("<<<<<<<<<<Select Blended>>>>>>>>>\n");
    printf("=================================\n");
    printf(" 1 : %s     %dWon \n", blenM[0].bName, blenM[0].bPrice);
    printf("                               \n");
    printf(" 2 : %s    %dWon \n", blenM[1].bName, blenM[1].bPrice);
    printf("                               \n");
    printf(" 3 : %s     %dWon \n", blenM[2].bName, blenM[2].bPrice);
    printf("                               \n");
    printf(" 4 : %s %dWon \n", blenM[3].bName, blenM[3].bPrice);
    printf("=================================\n");
    printf("=================================\n");
    printf(" Back to Menu            >> -1 \n\n");
    printf(" Go to payment           >> -2 \n");
    printf("=================================\n");

    return;
}
int selectBlendedMenu(blen blenM[], ad adM[]) // 블랜디드 메뉴 고르기
{                                             // 커피메뉴 선택 함수와 구조 동일
    int selectM = 0;
    int add1 = 0, add2 = 0;
    int cups = 0;

    while (1)
    {
        printBlendedMenu(blenM);
        printf("Select Blended(1 ~ 4) : ");
        scanf("%d", &selectM);

        if (selectM == -1 || selectM == -2)
            break;

        if (selectM > 4 || selectM < 1)
        {
            system("cls");
            printf("==================================\n");
            printf("    Choose again correctly!!    \n");
            printf("==================================\n");
            continue;
        }
        else
        {
            printf("\nHow many cups : ");
            scanf("%d", &cups);
            system("cls");
            printAddOption(adM);
            selectAddOption(adM, &add1, &add2);

            extendedPrice += (adM[add1 - 1].adPrice + adM[add2 - 1].adPrice);
            extendedPrice += (blenM[selectM - 1].bPrice * cups);
            break;
        }
    }
    printf("\n");

    return selectM;
}
void printDessertMenu(des desM[]) // 디저트 메뉴판
{
    printf("=================================\n");
    printf("<<<<<<<<<<Select Dessert>>>>>>>>>\n");
    printf("=================================\n");
    printf(" 1 : %s       %dWon \n", desM[0].desName, desM[0].desPrice);
    printf("                               \n");
    printf(" 2 : %s        %dWon \n", desM[1].desName, desM[1].desPrice);
    printf("                               \n");
    printf(" 3 : %s          %dWon \n", desM[2].desName, desM[2].desPrice);
    printf("                               \n");
    printf(" 4 : %s    %dWon \n", desM[3].desName, desM[3].desPrice);
    printf("=================================\n");
    printf("=================================\n");
    printf(" Back to Menu            >> -1 \n");
    printf(" Go to payment           >> -2 \n");
    printf("=================================\n");

    return;
}
int selectDessertMenu(des desM[]) // 디저트 메뉴 고르기
{                                 // 커피메뉴 선택 함수와 구조 동일
    int selectM = 0;
    int pieces = 0; // 디저트 수량 변수

    while (1)
    {
        printDessertMenu(desM);
        printf("Select Dessert(1 ~ 4) : ");
        scanf("%d", &selectM);

        if (selectM == -1 || selectM == -2)
            break;

        if (selectM > 4 || selectM < 1)
        {
            system("cls");
            printf("==================================\n");
            printf("    Choose again correctly!!    \n");
            printf("==================================\n");
            continue;
        }
        else
        {
            printf("How many pieces : ");
            scanf("%d", &pieces);
            extendedPrice += (desM[selectM - 1].desPrice * pieces); // 디저트 수량 곱해서 금액 결정
            break;
        }
    }
    printf("\n");

    return selectM;
}
void printAddOption(ad adM[]) // 추가 옵션 메뉴출력 함수
{
    printf("=================================\n");
    printf("<<<<<<<<<<<<< Option >>>>>>>>>>>>\n");
    printf("=================================\n");
    printf(" 1 : %s              %d \n", adM[0].adName, adM[0].adPrice);
    printf(" 2 : %s              %d \n", adM[1].adName, adM[1].adPrice);
    printf(" 3 : %s                   \n", adM[2].adName);
    printf("=================================\n");
    printf("=================================\n");

    return;
}
void selectAddOption(ad adM[], int *add1, int *add2) // 추가 옵션 선택 함수
{                                                    // 값을 두개 반환하기위해 포인터 사용
    printf("\nSelect two option(x y) : ");
    scanf("%d %d", add1, add2);

    return;
}
int inputMoney() // 결제하는 함수
{
    int amount = 0;
    int totalAmount = 0;
    int yesNo = 0;

    while (1) //1번 루트
    {
        if (extendedPrice != 0) // 결제할 금액이 0원이 아니라면 결제창
        {
            while (1) // 2번 루트  돈을 입력후 추가로 입력할지 말지 반복 루트
            {
                system("cls");
                printf("=================================\n");
                printf("=================================\n");
                printf("  The total amount is %d Won.\n", extendedPrice);
                printf("  current money : %d\n", totalAmount);
                printf("=================================\n");
                printf("=================================\n");
                printf("\nPlease put the money in : ");
                scanf("%d", &amount);
                totalAmount += amount;

                system("cls");
                printf("=============================================================\n");
                printf("  Would you like to add more money?(current money : %dWon)\n", totalAmount);
                printf("=============================================================\n");
                printf("\nyes = 1   no = 2   : ");
                scanf("%d", &yesNo);
                if (yesNo == 1)
                    continue; // 추가 수락할시 반복
                else
                    break; // 거절시 2번 루트 파괴
            }

            if (extendedPrice > totalAmount) // 총 금액보다 지불금액이 적을경우 경고후 다시 결제요청
            {
                system("cls"); // 그리고 다시 1번 루트로 -> 2번 루트로 이동 (지불금액은 누적)
                printf("\nPlease Again!!! Put the money back in.\n");
                continue;
            }
            else
            {
                extendedPrice -= totalAmount; // 입력금액이 총금액을 초과하거나 같을시 실행
                system("cls");
                printf("====================================================\n");
                printf("          The change is %d Won.\n", extendedPrice * (-1)); // 잔돈을 거슬러 준다(뺀 결과값 * -1)
                printf("====================================================\n");
                break; // break 1번 루트 파괴 함수 탈출 --> 메인함수
            }
        }
        else if (extendedPrice == 0)
        {
            printf("==============================\n");
            printf(" There is no list to pay for. \n"); // 총 금액이 0원일 경우 결제할 목록이 없다고 통보후
            printf("==============================\n");
            printf("Back to Menu = 1   End of Program = 2   : "); // 메뉴로 돌아갈지 프로그램을 끝낼지 선택
            scanf("%d", &yesNo);
            system("cls");
            if (yesNo == 1 || yesNo == 2)
                break; // break 1번루트 파괴 --> 메인함수 (yesNo == 1 or 2)
        }
    }
    return yesNo; // 결제금액이 0 원인 상태에서 끝낼지 초기메뉴로 돌아갈지 정하기 위한
} // yesNo값 반환
void ending()
{
    char pressA = 0;

    printf("\n");
    printf("============================================\n");
    printf("|           H y u n ' s  C A F E           |\n");
    printf("============================================\n");
    printf("============================================\n");
    printf("|                                          |\n");
    printf("|                                          |\n");
    printf("|            Have a nice day!!!            |\n");
    printf("|                                          |\n");
    printf("|                                          |\n");
    printf("================ Press Enter ===============\n\n");
    system("pause");

    return;
}