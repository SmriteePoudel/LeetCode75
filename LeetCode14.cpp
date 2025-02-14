// Product of the last K number
//Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

//Implement the ProductOfNumbers class:

//ProductOfNumbers() Initializes the object with an empty stream.
//void add(int num) Appends the integer num to the stream.
//int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
   


class ProductOfNumbers {
    private:
        vector<int> products;
    
    public:
        ProductOfNumbers() {
            products.push_back(1);  // Start with 1 as the neutral element for multiplication
        }
        
        void add(int num) {
            if (num == 0) {
                // If we encounter a zero, reset our products vector
                products.clear();
                products.push_back(1);
            } else {
                // Multiply the current number with the last running product
                products.push_back(products.back() * num);
            }
        }
        
        int getProduct(int k) {
            if (k >= products.size()) {
                // If k is larger than our current list of products (after accounting for zeros),
                // it means there's a zero in the range we're looking at
                return 0;
            }
            
            // The product of last k numbers is: 
            // (product of all numbers) / (product of all numbers except last k)
            return products.back() / products[products.size() - k - 1];
        }
    };