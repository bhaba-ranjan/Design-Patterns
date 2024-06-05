## Bridge Design Pattern

- Bridge is a structural design pattern that lets you split a large class or a set of closely related classes into two separate hierarchies—abstraction and implementation—which can be developed independently of each other.

- Problem see the diagram in `problem.png` if you increase a class or a color you need to introduce multiple subclasses.

- Now look at the solution `soln.png` if you **separate abstraction(shape class)** and create another dimension for **implementation(color interface)** then you can provide the shape class with a **reference object** to its implementation(different colors).

- This reference object creates a bridge like structure in the class diagram. Hence, Bridge pattern.