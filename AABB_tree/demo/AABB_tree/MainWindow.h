#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtOpenGL/qgl.h>
#include <CGAL/Qt/DemosMainWindow.h>

class QDragEnterEvent;
class QDropEvent;
class Scene;
class Viewer;
namespace Ui {
	class MainWindow;
}


class MainWindow : 
	public CGAL::Qt::DemosMainWindow
{
	Q_OBJECT
public:
	MainWindow(QWidget* parent = 0);
	~MainWindow();

	public slots:
		void updateViewerBBox();
		void open(QString filename);
		void setAddKeyFrameKeyboardModifiers(Qt::KeyboardModifiers);

		protected slots:

			// settings
			void quit();
			void readSettings();
			void writeSettings();

			// drag & drop
			void dropEvent(QDropEvent *event);
			void closeEvent(QCloseEvent *event);
			void dragEnterEvent(QDragEnterEvent *event);

			// file menu
			void on_actionLoadPolyhedron_triggered();

			// edit menu
			void on_actionClear_points_triggered();
			void on_actionClear_segments_triggered();
			void on_actionClear_distance_function_triggered();

			// algorithm menu
			void on_actionEdge_points_triggered();
			void on_actionInside_points_triggered();
			void on_actionBoundary_points_triggered();
			void on_actionRefine_bisection_triggered();
			void on_actionBoundary_segments_triggered();
			void on_actionSigned_distance_function_to_facets_triggered();
			void on_actionUnsigned_distance_function_to_edges_triggered();
			void on_actionUnsigned_distance_function_to_facets_triggered();

			// benchmark menu
			void on_actionBench_memory_triggered();
			void on_actionBench_distances_triggered();
			void on_actionBench_intersections_triggered();

			// view menu
			void on_actionView_points_triggered();
			void on_actionView_segments_triggered();
			void on_actionView_polyhedron_triggered();
			void on_actionView_distance_function_triggered();

private:
	Scene* m_pScene;
	Viewer* m_pViewer;
	Ui::MainWindow* ui;
};

#endif // ifndef MAINWINDOW_H