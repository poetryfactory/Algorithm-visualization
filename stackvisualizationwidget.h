#ifndef STACKVISUALIZATIONWIDGET_H
#define STACKVISUALIZATIONWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QStack>

class StackVisualizationWidget : public QWidget
{
    Q_OBJECT

public:
    StackVisualizationWidget(QWidget* parent = nullptr);

public slots:
    void pushFunction(const QString& functionName);
    void popFunction();

private:
    QStack<QString> callStack;
    QVBoxLayout* layout;
};

#endif // STACKVISUALIZATIONWIDGET_H
