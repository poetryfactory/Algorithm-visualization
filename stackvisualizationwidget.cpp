#include "stackvisualizationwidget.h"

StackVisualizationWidget::StackVisualizationWidget(QWidget* parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);
}

void StackVisualizationWidget::pushFunction(const QString& functionName)
{
    callStack.push(functionName);

    QLabel* label = new QLabel(functionName);
    layout->addWidget(label);
}

void StackVisualizationWidget::popFunction()
{
    if (!callStack.isEmpty())
    {
        callStack.pop();
        delete layout->takeAt(layout->count() - 1);
    }
}
