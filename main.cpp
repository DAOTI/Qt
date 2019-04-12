#include <QtGui/QApplication>
#include "mywidget.h"
#include <QObject>

#include <QTextCodec>
void SetCodec(QApplication &app)
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");//设置编码格式为UTF-8
    QTextCodec::setCodecForTr(codec);//调整QT字符，使非英文字符可用，这个函数的作用是设置传给tr函数时的默认字串编码
    QTextCodec::setCodecForLocale(codec);//这个函数主要用于设置和对本地文件系统读写时候的默认编码格式。
    QTextCodec::setCodecForCStrings(codec);//这个函数主要用在用字符常量或者QByteArray构造QString对象时使用的默认编码方式

}
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  SetCodec(a);
  MyWidget w;
  w.setWindowTitle(QObject::tr("文件读写工具 "));   
  w.show();
  return a.exec();
}

