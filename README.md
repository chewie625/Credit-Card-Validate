Mostly like the payment gateways have done it already. But here it is. 

### Basic Logic

- Total number of digits = 15 starts with '37' --> AMEX
- Total number of digits = 16 starts with '5' --> MASTERCARD
- Total number of digits > 14 starts with '4' --> VISA

    Check out these [List of Credit Card](https://developer.paypal.com/api/nvp-soap/payflow/integration-guide/test-transactions/#standard-test-cards)
    numbers for testing.



### To check Credit Card legitimacy:


- Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.

    e.g 4 0 0 3 6 0 0 0 0 0 0 0 0 0 1 4 

    So starting from the <mark>2nd last</mark> digit:

    1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2 

    = 2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

    Add product digits together, we have
    = 2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8  = **13**

- Add the sum to the sum of the digits that weren’t multiplied by 2.

    So starting from the <mark>last</mark> digit:

    4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 7; 

    7 + 13 (from digits x by 2 earlier ) = 20 


- If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

    20, last dight is 0. this credit card number is legit!!
