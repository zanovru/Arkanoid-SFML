#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "MyClass.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arkanoid Game", Style::Default);
    Ball ball(WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
    connect(&ball, SIGNAL(lose()), this, SLOT(changeWindow()));
    Platform platform(WINDOW_WIDTH/2, WINDOW_HEIGHT - 50);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    vector<Brick> bricks;
    bricks.reserve(BRICKS_X*BRICKS_Y);
    for(int i = 0; i < BRICKS_X; ++i)
        for(int j = 0; j < BRICKS_Y; j++)
        {
            bricks.emplace_back((i + 1) * (BRICK_WIDTH + 10) + 150 , (j + 2) * (BRICK_HEIGHT + 10));
        }
    while(window.isOpen())
    {
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed)
            {
                window.close();
            }
        }
        if(bricks.size() == 0)
        {
           window.close();
           ui->pushButton->hide();
           ui->label->setText("You win!");
           ui->label->setAlignment(Qt::AlignCenter);
           ui->label->show();
           this->show();
        }
        window.clear(Color::Black);
        ball.update(window);
        platform.update();
        testIntersection(platform, ball);
        for(auto& brick : bricks) testIntersection(brick, ball);
        bricks.erase(remove_if(bricks.begin(), bricks.end(), [](Brick& brick){return brick.getIsDestroyed();}), bricks.end());
        window.draw(platform.getShape());
        window.draw(ball.getShape());
        for(auto& brick : bricks) window.draw(brick.getShape());
        window.display();

    }
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::changeWindow()
{
    ui->pushButton->hide();
    ui->label->setText("You lose!");
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->show();
    this->show();
}
