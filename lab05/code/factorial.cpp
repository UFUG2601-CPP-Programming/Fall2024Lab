// Recursive function to check if a string is a palindrome
#include <iostream> 

// Tail recursive version of factorial
int tail_factorial(int n){
    if (n == 0){
        return 1;
    }else{
        return n * tail_factorial(n - 1);
    }
}
    
// Head recursive version of factorial
int head_factorial(int n, int num=1){
    if (n > 0){
        return head_factorial(n - 1, num * n);
    }else{
        return num;
    }
}


int main() {
    std::cout << tail_factorial(10) << std::endl;
    std::cout << head_factorial(10) << std::endl;
    return 0; // Returning 0 to indicate successful execution of the program
}