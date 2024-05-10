
### 5.3: Multimedia with Qt Multimedia

**Overview**
Qt Multimedia oﬀers classes to handle audio and video within Qt applications, supporting playback and recording functionalities.
* **QMediaPlayer:** Used to play audio and video ﬁles.
* **QMediaRecorder:** Used to record audio and video from input devices.
* **QVideoWidget:** A widget used to display video.

**Example:** Creating a simple media player to play a video ﬁle.

```
#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget> 
 
int main(int argc, char *argv[]) { 
    QApplication app(argc, argv); 
 
    QMediaPlayer *player = new QMediaPlayer; 
    QVideoWidget *videoWidget = new QVideoWidget; 
 
    player->setVideoOutput(videoWidget); 
    player->setMedia(QUrl::fromLocalFile("/path/to/your/video.mp4")); 
    videoWidget->show(); 
    player->play(); 
 
    return app.exec(); 
} 
```
