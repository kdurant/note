# class

## 基本使用
```verilog
program class_t;
    class packet;
        // members in class
        integer size;
        integer payload [];
        integer i;
        // Constructor
        function new (integer size);
        begin
            this.size = size;
            payload = new[size];
            for (i=0; i < this.size; i ++) begin
                payload[i] = $random;
            end 
        end 
        endfunction
        // Task in class (object method)
        task print ();
        begin
            $write("Payload : ");
            for (i=0; i < size; i ++) begin
                $write("%x ",payload[i]);
            end
            $write("\n");
        end 
        endtask
        // Function in class (object method)
        function integer get_size();
        begin
            get_size = this.size;
        end
        endfunction
    endclass

 packet pkt;

 initial begin
     pkt = new(5);
     pkt.print();
     $display ("Size of packet %0d",pkt.get_size());
 end

endprogram
```
1. `program`里可以声明, 使用`class`
2. program可以直接放到一个sv文件里, 对其进行单独编译仿真, 和使用`module`一样

## 静态成员
当一个对象在多个地方使用时，我们希望该对象的某些成员在所有实例中具有相同的值。假设我们修改了第一个对象实例中的变量，并且当我们希望该值反映在其他实例中时。为此，SystemVerilog提供静态类成员。

```verilog
`define PRINT task print (); \
  begin \
    $write("%s -> Size is %0d\n",this.name, this.size); \
 end \
endtask

program class_static;
  // Class with constructor, with no parameter
  class A;
     // Make size as static
     static integer size;
     string name;
     // Constructor
     function new (string name);
       begin
         this.name = name;
         this.size = 0;
       end 
     endfunction
     // Increment size task
     task inc_size();
       begin
         this.size ++;
         $write("%s -> size is incremented\n",this.name);
       end
     endtask
     // Task in class (object method)
     `PRINT
   endclass

   A a,b,c;

   initial begin
     a = new("A");
     b = new("B");
     c = new("C");
     a.inc_size();
     a.print();
     b.print();
     c.print();
     c.inc_size();
     a.print();
     b.print();
     c.print();
   end

endprogram
```

## 静态方法
方法可以声明为静态的。静态方法受所有类作用域和访问规则的约束，但其行为类似于可以在类之外调用的常规子例程，即使没有类实例化。静态方法不能访问非静态成员(类属性或方法)，但是它可以直接访问静态类属性或调用同一类的静态方法。访问静态方法主体中的非静态成员或特殊句柄是非法的，会导致编译器错误。静态方法不能是虚拟的。
```verilog
`define PRINT task print (); \
 begin \
   $write("%s -> Size is %0d\n",this.name, this.size); \
 end \
endtask

program class_static_method;
  // Class with constructor, with no parameter
  class A;
     // Make size as static
     static integer size;
     string name;
     // Constructor
     function new (string name);
       begin
         this.name = name;
         this.size = 0;
       end 
     endfunction
     // static Increment size task
     static task inc_size();
       begin
         size ++; // Ok to access static member
         $write("size is incremented\n");
         // Not ok to access non static member name          
         //$write("%s -> size is incremented\n",name);
       end
     endtask
     // Task in class (object method)
     `PRINT
   endclass

   A a;

   initial begin
     a = new("A");
     a.inc_size();
     a.print();
   end

endprogram
```

## 类常量成员

## 类互相赋值
浅copy

## 继承和子类

## super函数

## 数据隐藏和封装

## 虚类

