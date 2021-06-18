#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QLineEdit>
#include <QLabel>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QString>
#include<QStack>
#include<QTime>
#include<iterator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Formula_linkActivated(const QString &link);
    void buttonZeroClicked();
    void buttonOneClicked();
    void buttonTwoClicked();
    void buttonThreeClicked();
    void buttonFourClicked();
    void buttonFiveClicked();
    void buttonSixClicked();
    void buttonSevenClicked();
    void buttonEightClicked();
    void buttonNineClicked();


    void buttonAddClicked();//+
    void buttonSubClicked();//-
    void buttonMulClicked();//乘
    void buttonDivClicked();//除
    void buttonTimClicked(); //时间
    void buttonDecClicked();//小数点
    void buttonBotClicked(); //加减号

    void buttonEquClicked();//等于号

    void buttonLefClicked();//左括号
    void buttonRigClicked();//右括号

    void buttonCEClicked();//CE
    void buttonACClicked();//AC

private:
    QLineEdit *inputLine;//显示框
    QString input="0"; //输入框
    bool flat=false;
          //0-9按钮
    QPushButton *zeroButton;
    QPushButton *oneButton;
    QPushButton *twoButton;
    QPushButton *threeButton;
    QPushButton *fourButton;
    QPushButton *fiveButton;
    QPushButton *sixButton;
    QPushButton *sevenButton;
          QPushButton *eightButton;
          QPushButton *nineButton;
          QLabel *label;


          QPushButton *addButton;
          QPushButton *subButton;
          QPushButton *divButton;
          QPushButton *mulButton;
          QPushButton *equButton;
          QPushButton *timButton; //Time
          QPushButton *decButton;
          QPushButton *botButton;

          QPushButton *CEButton;
          QPushButton *ACButton;
          QPushButton *lefButton;
          QPushButton *rigButton;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
