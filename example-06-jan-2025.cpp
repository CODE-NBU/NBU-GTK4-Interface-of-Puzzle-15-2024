#include <string>
#include <cstdlib>
#include <iostream>

#include <gtkmm/grid.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/application.h>

class MainWindow : public Gtk::Window {
	private: static const int SIZE = 4;

	private: Gtk::Grid grid;

	private: Gtk::Button button01;
	private: Gtk::Button button02;
	private: Gtk::Button button03;
	private: Gtk::Button button04;
	private: Gtk::Button button05;
	private: Gtk::Button button06;
	private: Gtk::Button button07;
	private: Gtk::Button button08;
	private: Gtk::Button button09;
	private: Gtk::Button button10;
	private: Gtk::Button button11;
	private: Gtk::Button button12;
	private: Gtk::Button button13;
	private: Gtk::Button button14;
	private: Gtk::Button button15;
	private: Gtk::Button button00;

	private: Gtk::Button *buttons[ SIZE ][ SIZE ];

	private: void swap(Gtk::Button *, Gtk::Button *);

	private: void move(Gtk::Button *);

	private: void shuffle();

	protected: void on_button_clicked(Gtk::Button *);

	public: MainWindow();

	public: ~MainWindow() override;
};

MainWindow::MainWindow() : button01("01"), button02("02"), button03("03"), button04("04"), button05("05"), button06("06"), button07("07"), button08("08"), button09("09"), button10("10"), button11("11"), button12("12"), button13("13"), button14("14"), button15("15"), button00("  ") {
	button01.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button01));
	button02.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button02));
	button03.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button03));
	button04.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button04));
	button05.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button05));
	button06.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button06));
	button07.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button07));
	button08.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button08));
	button09.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button09));
	button10.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button10));
	button11.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button11));
	button12.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button12));
	button13.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button13));
	button14.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button14));
	button15.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button15));
	button00.signal_clicked().connect(sigc::bind(sigc::mem_fun(*this, &MainWindow::on_button_clicked), &button00));

	grid.attach(button01, 0, 0);
	grid.attach(button02, 1, 0);
	grid.attach(button03, 2, 0);
	grid.attach(button04, 3, 0);
	grid.attach(button05, 0, 1);
	grid.attach(button06, 1, 1);
	grid.attach(button07, 2, 1);
	grid.attach(button08, 3, 1);
	grid.attach(button09, 0, 2);
	grid.attach(button10, 1, 2);
	grid.attach(button11, 2, 2);
	grid.attach(button12, 3, 2);
	grid.attach(button13, 0, 3);
	grid.attach(button14, 1, 3);
	grid.attach(button15, 2, 3);
	grid.attach(button00, 3, 3);

	buttons[ 0 ][ 0 ] = &button01;
	buttons[ 1 ][ 0 ] = &button02;
	buttons[ 2 ][ 0 ] = &button03;
	buttons[ 3 ][ 0 ] = &button04;
	buttons[ 0 ][ 1 ] = &button05;
	buttons[ 1 ][ 1 ] = &button06;
	buttons[ 2 ][ 1 ] = &button07;
	buttons[ 3 ][ 1 ] = &button08;
	buttons[ 0 ][ 2 ] = &button09;
	buttons[ 1 ][ 2 ] = &button10;
	buttons[ 2 ][ 2 ] = &button11;
	buttons[ 3 ][ 2 ] = &button12;
	buttons[ 0 ][ 3 ] = &button13;
	buttons[ 1 ][ 3 ] = &button14;
	buttons[ 2 ][ 3 ] = &button15;
	buttons[ 3 ][ 3 ] = &button00;

	int width = button00.get_allocation().get_x() + button00.get_allocation().get_width();
	int height = button00.get_allocation().get_y() + button00.get_allocation().get_height();

	set_title("Puzzle 15");
	set_default_size(width, height);
	set_child(grid);
}

void MainWindow::swap(Gtk::Button *empty, Gtk::Button *full) {
	empty->set_label( full->get_label() );
	full->set_label( "  " );
}

void MainWindow::move(Gtk::Button *sender) {
	int x=-1, y=-1;

	for(int j=0; j<SIZE; j++) {
		for(int i=0; i<SIZE; i++) {
			if(buttons[i][j] == sender) {
				x = i;
				y = j;

				i = SIZE;
				j = SIZE;
			}
		}
	}

	if(x-1>=0 && buttons[x-1][y]->get_label() == "  ") {
		swap(buttons[x-1][y], sender);
	} else if(x+1<SIZE && buttons[x+1][y]->get_label() == "  ") {
		swap(buttons[x+1][y], sender);
	} else if(y-1>=0 && buttons[x][y-1]->get_label() == "  ") {
		swap(buttons[x][y-1], sender);
	} else if(y+1<SIZE && buttons[x][y+1]->get_label() == "  ") {
		swap(buttons[x][y+1], sender);
	}
}

void MainWindow::shuffle() {
	for(int r=0; r<SIZE*SIZE*SIZE*SIZE; r++) {
		int x = rand() % 4;
		int y = rand() % 4;

		if(x-1>=0 && buttons[x-1][y]->get_label() == "  ") {
			move( buttons[x][y] );
		} else if(x+1<SIZE && buttons[x+1][y]->get_label() == "  ") {
			move( buttons[x][y] );
		} else if(y-1>=0 && buttons[x][y-1]->get_label() == "  ") {
			move( buttons[x][y] );
		} else if(y+1<SIZE && buttons[x][y+1]->get_label() == "  ") {
			move( buttons[x][y] );
		} else {
			r--;
		}
	}

	while(button00.get_label() != "  ") {
		move( buttons[rand()%4][rand()%4] );
	}
}

void MainWindow::on_button_clicked(Gtk::Button *sender) {
	if(sender->get_label() == "  ") {
		shuffle();
	} else {
		move( sender );
	}
}

MainWindow::~MainWindow() {
}

int main(int argc, char* argv[]) {
	srand( time(NULL) );

	auto app = Gtk::Application::create("org.gtkmm.examples.base");

	return app->make_window_and_run<MainWindow>(argc, argv);
}
