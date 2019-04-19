#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QTimer>
#include <QTime>

#include "widgets/ledindicator.h"

enum class LightState
{
    State1 = 0,
    State2 = 1,
    State3 = 2
};

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget widget;
    LedIndicator *leds[11];

    {
        auto layout = new QHBoxLayout(&widget);

        for(std::size_t i = 0; i < 11; i++)
        {
            leds[i] = new LedIndicator(&widget);
            layout->addWidget(leds[i]);

            if(i == 2 || i == 6)
                layout->addSpacing(50);
        }

        widget.setLayout(layout);
    }

    QTimer timer;
    timer.setInterval(100);
    QObject::connect(&timer, &QTimer::timeout, [leds](){
        const auto time = QTime::currentTime();
        auto hour = time.hour();
        auto minute = time.minute();
        auto second = time.second();

        LightState states[11];

        for(int i = 0; i < 3; i++)
        {
            auto digit = hour % 3;
            hour -= digit;
            hour /= 3;
            states[2 - i] = LightState(digit);
        }

        for(int i = 0; i < 4; i++)
        {
            auto digit = minute % 3;
            minute -= digit;
            minute /= 3;
            states[6 - i] = LightState(digit);
        }

        for(int i = 0; i < 4; i++)
        {
            auto digit = second % 3;
            second -= digit;
            second /= 3;
            states[10 - i] = LightState(digit);
        }

        for(std::size_t i = 0; i < 11; i++)
        {
            switch(states[i])
            {
            case LightState::State1:
                leds[i]->setColor(Qt::red);
                break;
            case LightState::State2:
                leds[i]->setColor(Qt::green);
                break;
            case LightState::State3:
                leds[i]->setColor(Qt::blue);
                break;
            }
        }
    });

    widget.show();
    timer.start();

    return app.exec();
}
