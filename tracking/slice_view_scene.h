#ifndef SLICE_VIEW_SCENE_H
#define SLICE_VIEW_SCENE_H
#include <QGraphicsScene>
#include <vector>
#include "image/image.hpp"
#include <QStatusBar>
class ODFModel;
class tracking_window;
class slice_view_scene : public QGraphicsScene
{
    Q_OBJECT
public:
    slice_view_scene(tracking_window& cur_tracking_window_,ODFModel* handle_):
        display_ratio(8.0),sel_mode(0),mid_down(false),
            cur_tracking_window(cur_tracking_window_),
            handle(handle_),statusbar(0)
    {

    }
    double display_ratio;
    unsigned char sel_mode;
    QStatusBar* statusbar;
private:
    tracking_window& cur_tracking_window;
    ODFModel* handle;
    image::color_image slice_image,mosaic_image;
public:
    unsigned int mosaic_size;
private:
    // record the mouse press points
    std::vector<image::vector<3,short> >sel_coord;
    std::vector<image::vector<2,short> >sel_point;
    int cur_region;
    bool mouse_down;
    bool mid_down;
    int cX, cY;

    QImage view_image;
    void show_fiber(QPainter& painter,float* dir, unsigned int x, unsigned int y);
    // update cursor info
protected:
    void mouseDoubleClickEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    void mousePressEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    void mouseMoveEvent ( QGraphicsSceneMouseEvent * mouseEvent );
    void mouseReleaseEvent ( QGraphicsSceneMouseEvent * mouseEvent );
public slots:
    void show_slice();
    void zoom_in();
    void zoom_out();
    void catch_screen();
    void copyClipBoard();
    void center();
    void save_slice_as();
signals:
    void need_update();

};
#endif // SLICE_VIEW_SCENE_H
