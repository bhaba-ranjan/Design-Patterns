## State Design Pattern.
- This pattern will be used when there is a state translation between objects dependent with some actions. Check `example.png`.

- You created `vending_machine.hpp` file with just definition bcz; the `concrete_state.hpp` can use the full definition of `vending_machine.hpp` if you don't give the full definition the `setState` will not be callable from inside concrete class.

- However, the real implementation is define in `vending_machine.cpp` file because it uses classes from `concrete_sate.hpp`.