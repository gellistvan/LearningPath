
### 2.5: File Handling

`QFile` and `QDir` are crucial for handling ﬁle input/output operations and directory management.
* QFile: Manages ﬁle I/O.
* QDir: Manages directory and path information.

**Example**: Reading and writing ﬁles with error handling:

```
QFile file("data.txt"); 
if (!file.open(QIODevice::ReadWrite)) { 
    qWarning("Cannot open file for reading"); 
} else { 
    QTextStream in(&file); 
    while (!in.atEnd()) { 
        QString line = in.readLine(); 
        qDebug() << line; 
    } 
    QTextStream out(&file); 
    out << "New line of text\n"; 
    file.close(); 
} 
```

```
QFile file("example.txt"); 
if (file.open(QIODevice::ReadWrite)) { 
    QTextStream stream(&file); 
    stream << "Hello, Qt!"; 
    file.flush();  // Write changes to disk 
    file.seek(0);  // Go back to the start of the file 
    QString content = stream.readAll(); 
    qDebug() << content; 
    file.close(); 
} 
```