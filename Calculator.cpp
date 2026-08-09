#include <iostream>
#include <string>
#include <vector>

//Declaring the main list of numbers
std::vector<int> numbers = {};

//Function to show the welcome message
void welcome()
{
    std::cout << "====================\n";
    std::cout << "=====CALCULATOR=====\n";
    std::cout << "====================\n";

    std::cout << "\n";
    
    std::cout << "Welcome to my Calculator\n";
    std::cout << "Here you can add a list of numbers, multiply them and subtract or divide two numbers\n";
}

//Function to show the main menu
void menu()
{
    std::cout << "Enter 1 : To Add two or more numbers.\n";
    std::cout << "Enter 2 : To Subtract two numbers.\n";
    std::cout << "Enter 3 : To Multiply two or numbers.\n";
    std::cout << "Enter 4 : To Divide one number by other number.\n";
    std::cout << "Enter 5 : To Exit the program.\n";
}

//Function to input the numbers
void input(std::vector<int>& nums, int& n)
{
    std::cout << "Enter the numbers : \n";
    for(int i=0;i<n;i++)
    {
        int temp = 0;
        std::cin >> temp;
        nums.push_back(temp);
    }
}

//Function to add the numbers
int add(std::vector<int>& nums, int& n)
{
    int a = 0;
    for(int i=0;i<n;i++)
    {
        a = a + nums[i];
    }
    return a;
}

//Function to subtract the numbers
int subtract(std::vector<int>& nums)
{
    int s;
    if(nums[0] > nums[1])
    {
        s = nums[0] - nums[1];
    }
    else
    {
        s = nums[1] - nums[0];
    }
    return s;
}

//Function to multiply the numbers
int multiply(std::vector<int>& nums, int& n)
{
    int p = 1;
    for(int i=0;i<n;i++)
    {
        p = p*nums[i];
    }
    return p;
}

//Function to divide the numbers
double divide(std::vector<int>& nums)
{
    double d = 0.0;
    if(nums[1] != 0)
    {
        d = static_cast<double>(nums[0])/nums[1];
    }
    return d;
}

//Main Function to make the program execute and call the above functions
int main()
{
    int ch = 0;
    int n;

    //calling the welcome and main menu function
    welcome();
    menu();

    //Inputting the choice of the user
    std::cout << "Enter your choice : ";
    std::cin >> ch;

    std::cout << "\n";

    //Checking the invalid input re-inputing a valid input
    if(ch>5)
    {
        while(ch > 5)
        {
            std::cout << "Invalid Choice!!!!\n";
            std::cout << "Enter a valid choice : ";
            std::cin >> ch;
        }
    }
    std::cout << "\n";

    //if-else conditioning to make the menu work
    while(ch<5)
    {
        //Block if the choice entered is for sum
        if(ch==1)
        {
            int sum = 0;
            std::cout << "Enter how many numbers will input to add : ";
            std::cin >> n;

            //Calling Input funtion and Add Function by Reference
            input(numbers, n);
            sum = add(numbers, n);

            std::cout << "Sum of the numbers : " << sum;
            std::cout << "\n";
        }

        //Block if the choice entered is for subtraction
        else if(ch==2)
        {
            int sub = 0;
            n = 2;

            //Calling Input funtion and Subtract Function by Reference
            input(numbers, n);
            sub = subtract(numbers);

            std::cout << "Difference Between the two numbers : " << sub;
            std::cout << "\n";
        }

        //Block if the choice entered is for multiplication
        else if(ch==3)
        {
            int prod = 1;
            std::cout << "Enter how many numbers will input to add : ";
            std::cin >> n;
            
            //Calling Input funtion and Multiply Function by Reference
            input(numbers, n);
            prod = multiply(numbers, n);

            std::cout << "Product of the numbers : " << prod;
            std::cout << "\n";
        }

        //Block if the choice entered is for division
        else if(ch==4)
        {
            double div = 0.0;
            n = 2;

            //Calling Input funtion and Divide Function by Reference
            input(numbers, n);
            while(numbers[1] == 0)
            {
                std::cout << "INVALID INPUT : DIVISION BY ZERO!!!!!!\n";
                int temp = 0;
                std::cout << "Enter a valid input : ";
                std::cin >> temp;
                numbers[1] = temp;
            }
            div = divide(numbers);

            std::cout << "Quotient when " << numbers[0] << " is divded by " << numbers[1] << " is : " << div;
            std::cout << "\n";
        }

        //Inputting the next choice 
        std::cout << "Enter Your Next Choice : ";
        std::cin >> ch;
        std::cout << "\n";

        //Nullifying the list for next choice
        numbers = {};
    }

    //Final closing thank you message if the user has exited the program
    std::cout << "THANK YOU!!!!\n";
    std::cout << "Hope you found my calculator useful\n";
}