## 工厂模式
### 工厂方法模式
#### 定义
&emsp;&emsp;定义一个创建对象的接口，但有子类决定要实例的类是哪一个。工厂方法让类把实例化推迟到子类。
#### 优点
&emsp;&emsp;(1)更符合开闭原则。新增一种产品时，只需要增加相应的产生具体产品类和相应的工厂子类即可。  
&emsp;&emsp;(2)符合单一职责原则。每个具体工厂类只负责创建对应的产品。  
&emsp;&emsp;(3)让扩展变得简单，让继承变得可行，增加了多态性的体现
#### 缺点
&emsp;&emsp;(1)一个具体工厂只能创建一种具体产品  
&emsp;&emsp;(2)添加新的产品时，除了添加新的产品类，还需提供对应的具体工厂类，在一定程度上增加了系统的复杂度。  
&emsp;&emsp;(3)考虑到系统的可扩展性，需要引入抽象层，在客户端代码中均使用抽象层进行定义，增加了系统的抽象度和系统的复杂度。
#### 运用场景
&emsp;&emsp;(1)当一个类希望通过其子类来指定创建对象时。在工厂方法模式中，对于抽象工厂类只需要提供一个创建产品的接口，而由其子类来确定具体要创建的对象，利用面向对象的多态性和里氏代换原则，在程序运行时，子类对象将覆盖父类对象，从而使得系统更容易扩展。  
&emsp;&emsp;(2)当一个类不知道它所需要的对象的类时。在工厂方法模式中，客户端不需要知道具体产品类的类名，只需要知道所对应的工厂即可。  
&emsp;&emsp;(3)将创建对象的任务委托给多个工厂子类中的某一个，客户端在使用时可以无须关心是哪一个工厂子类创建产品子类，需要时再动态指定，可将具体工厂类的类名存储在配置文件或数据库中。
### 抽象工厂模式
#### 定义
&emsp;&emsp;定义一个接口，用于创建相关或依赖对象的家族，而不需要明确指定具体类。  
&emsp;&emsp;抽象工厂允许客户使用抽象的接口来创建一组相关的产品，而不需要知道具体产出的产品是什么。
#### 优点
&emsp;&emsp;(1)降低耦合。抽象工厂模式将具体产品的创建延迟到具体工厂的子类中，这样将对象的创建封装起来，可以减少客户端与具体产品类之间的依赖，从而使系统耦合度低，这样更有利于后期的维护和扩展。  
&emsp;&emsp;(2)更符合开-闭原则。新增一种产品类时，只需要增加相应的具体产品类和相应的工厂子类即可。  
&emsp;&emsp;(3)符合单一职责原则。每个具体工厂类只负责创建对应的产品。  
#### 缺点
&emsp;&emsp;抽象工厂模式很难支持新种类产品的变化。这是因为抽象工厂接口中已经确定了可以被创建的产品集合，如果需要添加新产品，此时就必须去修改抽象工厂的接口，这样就涉及到抽象工厂类的以及所有子类的改变，这样也就违背了“开发——封闭”原则。
#### 运用场景
&emsp;&emsp;(1)这个系统有多个系列产品，而系统中只消费其中某一系列产品。  
&emsp;&emsp;(2)系统要求提供一个产品类的库，所有产品以同样的接口出现，客户端不需要依赖具体实现。