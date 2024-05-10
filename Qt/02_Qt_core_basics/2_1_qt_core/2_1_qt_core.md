## Chapter 2: Qt Core Basics
This chapter will guide students through essential classes, the object model, event management, memory management, and ﬁle handling. Here’s a detailed breakdown of the elements for Chapter 2, complete with examples and key usage details.
### 2.1: Qt Core Classes

#### Core Classes Overview
Qt provides a wide range of core classes that handle non-GUI tasks necessary for application development. These classes include data handling, ﬁle I/O, threading, and more. Each class is designed to oﬀer ﬂexibility and robust functionality to the Qt framework.
#### QString
Manages immutable Unicode character strings and provides numerous functions for string manipulation, such as slicing, concatenation, conversion, and comparison.

**Key Properties and Usage:**

* `length()`: Returns the number of characters in the string.
* `isEmpty()`: Checks if the string is empty.
* `toInt()`, `toDouble()`: Converts the string to integers or ﬂoating-point numbers.
* `split()`: Divides the string into substrings based on a delimiter.

**Example:** More complex operations with `QString`:

```
QString s = "Hello, world!"; 
qDebug() << "Length:" << s.length(); 
qDebug() << "Empty?" << s.isEmpty(); 
QStringList parts = s.split(','); 
qDebug() << "Split result:" << parts.at(0).trimmed();  // Output: "Hello"

QString s = "Temperature"; 
double temp = 24.5; 
QString text = s + ": " + QString::number(temp); 
```
#### QVariant
Holds a single value of a variety of data types.

**Key Properties and Usage:**

* `isValid()`: Determines if the variant contains a valid data.
* `canConvert<T>()`: Checks whether the stored value can be converted to a speciﬁed type.

**Example**: Using `QVariant` to store diﬀerent types and retrieve values:

```
QVariant v(42);  // Stores an integer
qDebug() << "Is string?" << v.canConvert<QString>(); 
qDebug() << "As string:" << v.toString(); 
v.setValue("Hello Qt"); 
qDebug() << "Now a string?" << v.canConvert<QString>(); 
```