In C++11, the `<random>` header introduces a comprehensive random number generation library that provides facilities for generating random numbers and distributions in a more flexible and efficient manner than previous methods such as using `rand()`. Here are the key components of the `<random>` header in C++11:

1. **Random Number Engines (Generators)**: These are the core of the random number generation process. They are algorithms that generate raw random numbers. Examples include:
    - `std::default_random_engine`: A versatile engine that provides a default random number generator.
    - `std::mt19937`: A Mersenne Twister engine that generates high-quality 32-bit random numbers.
    - `std::mt19937_64`: A 64-bit version of the Mersenne Twister engine.
    - `std::minstd_rand`: A minimal standard random number generator.
    - `std::ranlux24_base`, `std::ranlux48_base`: RANLUX algorithms at different levels of luxury.

2. **Distributions**: These use the outputs from the engines to generate random numbers that follow a specific statistical distribution. This allows programmers to generate numbers according to distributions like uniform, normal, or binomial. Examples of distributions include:
    - `std::uniform_int_distribution<>`: Generates a uniform distribution of integers.
    - `std::uniform_real_distribution<>`: Produces a uniform distribution of floating-point numbers.
    - `std::normal_distribution<>`: Generates normally distributed (Gaussian) numbers.
    - `std::binomial_distribution<>`: Generates numbers according to a binomial distribution.
    - `std::poisson_distribution<>`: Generates numbers according to a Poisson distribution.
    - `std::exponential_distribution<>`: Generates numbers according to an exponential distribution.

3. **Random Device**: This is a non-deterministic random number generator that can be used to seed the deterministic engines for more randomness.
    - `std::random_device`: Often used to provide a seed for the more deterministic random number generators to ensure greater randomness.

4. **Seed Sequences**: These provide a mechanism to generate seeds from a single initial value. This is useful when you need a reproducible sequence of random numbers but with better initialization than a single seed value.
    - `std::seed_seq`: Facilitates the creation of multiple seeds from a single input.

5. **Utility Functions and Classes**: These include functions and classes that help manage and manipulate the random number generators and distributions.
    - `std::generate_canonical`: This function template generates floating-point values uniformly distributed across the range [0,1).

Using the `<random>` header provides better control, predictability, and efficiency in generating random numbers compared to the older `rand()` and `srand()` functions, making it a valuable tool for simulations, games, testing frameworks, and any application requiring statistical randomness.