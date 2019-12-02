#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <iostream>

int main()

{
    int menu;
    float R1, R2, R3, RT, VR1, VR2, VR3, PR1, PR2, PR3, E, PE, IE, IR1, IR2, IR3, R, I;

    std::cout << "\t\t Programa para calculo circuito serie ou paralelo\n";
    std::cout << "Digite a tensao do circuito (V): ";
    std::cin >> E;
    std::cout << "Digite o valor do resistor R1 (Ohms): ";
    std::cin >> R1;
    std::cout << "Digite o valor do resistor R2 (Ohms): ";
    std::cin >> R2;
    std::cout << "Digite o valor do resistor R3 (Ohms): ";
    std::cin >> R3;
    system("cls");
    std::cout << "Escolha uma das opcoes:\n\t1 - Calculo circuito serie\n\t2 - Calculo circuito paralelo\n\n";
    std::cin >> menu;
    if (menu == 1)
    {
        system("cls");
        std::cout << "\t\tCalculo de circuito serie:\n";
        RT = R1 + R2 + R3;
        IE = E / RT;
        IR1 = IR2 = IR3 = IE;
        VR1 = IR1 * R1;
        VR2 = IR2 * R2;
        VR3 = IR3 * R3;
    }
    else
    {
        system("cls");
        std::cout << "\t\tCalculo de circuito paralelo:\n";
        RT = (R1 * R2 * R3) / (R2 * R3 + R1 * R2 + R1 * R3);
        IE = E / RT;
        IR1 = E / R1;
        IR2 = E / R2;
        IR3 = E / R3;
        VR1 = VR2 = VR3 = E;
    }
    PE = IE * E;
    PR1 = VR1 * IR1;
    PR2 = VR2 * IR2;
    PR3 = VR3 * IR3;

    std::cout << "\t\t\tResultados:\n";
    std::cout << "r Total: " << RT << " (Ohms)\n";
    std::cout << "i Fonte: " << IE << " A\n";
    std::cout << "p Fonte: " << PE << " Watts\n";
    std::cout << "Correntes: \n"
              << "r1 [" << IR1 << "] r2 [" << IR2 << "] r3 [" << IR3 << "]\n";
    std::cout << "DDPs: \n"
              << "r1 [" << VR1 << "] r2 [" << VR2 << "] r3 [" << VR3 << "]\n";
    std::cout << "Potencias: \n"
              << "r1 [" << PR1 << "] r2 [" << PR2 << "] r3 [" << PR3 << "]\n";
    return 0;
}