/********************************************************************************
** Form generated from reading UI file 'tracking_window.ui'
**
** Created: Wed Nov 28 12:31:49 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKING_WINDOW_H
#define UI_TRACKING_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "plot/qcustomplot.h"
#include "qcolorcombobox.h"

QT_BEGIN_NAMESPACE

class Ui_tracking_window
{
public:
    QAction *actionNewRegion;
    QAction *actionOpenRegion;
    QAction *actionSaveRegionAs;
    QAction *actionDeleteRegion;
    QAction *actionOpenTract;
    QAction *actionSaveTractAs;
    QAction *actionSaveTractFA;
    QAction *actionDeleteRegionAll;
    QAction *actionDeleteTract;
    QAction *actionDeleteTractAll;
    QAction *actionShift_X;
    QAction *actionShift_X_2;
    QAction *actionShift_Y;
    QAction *actionShift_Y_2;
    QAction *actionShift_Z;
    QAction *actionShift_Z_2;
    QAction *actionFlip_X;
    QAction *actionFlip_Y;
    QAction *actionFlip_Z;
    QAction *actionDilation;
    QAction *actionErosion;
    QAction *actionSmoothing;
    QAction *actionNegate;
    QAction *actionDefragment;
    QAction *actionWhole_brain_seeding;
    QAction *actionSelect_Tracts;
    QAction *actionUndo;
    QAction *actionDelete;
    QAction *actionTrim;
    QAction *actionCut;
    QAction *actionZoom_In;
    QAction *actionZoom_Out;
    QAction *actionSagittal_view;
    QAction *actionCoronal_View;
    QAction *actionAxial_View;
    QAction *actionQuantitative_anisotropy_QA;
    QAction *actionMerge_All;
    QAction *actionSave_Screen;
    QAction *actionSave_ROI_Screen;
    QAction *actionLoad_Camera;
    QAction *actionSave_Camera;
    QAction *actionEndpoints_to_seeding;
    QAction *actionTracts_to_seeds;
    QAction *actionSave_Rotation_Images;
    QAction *actionPaint;
    QAction *actionInsert_T1_T2;
    QAction *actionAdd_surface;
    QAction *actionSave_mapping;
    QAction *actionLoad_mapping;
    QAction *actionStatistics;
    QAction *actionK_means;
    QAction *actionEM;
    QAction *actionHierarchical;
    QAction *actionSet_Color;
    QAction *actionSave_Tracts_Colors_As;
    QAction *actionOpen_Colors;
    QAction *actionSave_Voxel_Data_As;
    QAction *actionTDI_Diffusion_Space;
    QAction *actionTDI_Import_Slice_Space;
    QAction *actionTDI_Subvoxel_Diffusion_Space;
    QAction *actionSave_Tracts_in_Current_Mapping;
    QAction *actionThreshold;
    QAction *actionRedo;
    QAction *actionCopy_to_clipboard;
    QAction *actionSave_Anisotrpy_Map_as;
    QAction *actionRestore_window_layout;
    QAction *actionSave_Endpoints_in_Current_Mapping;
    QAction *actionMove_Object;
    QAction *actionSave_Report_as;
    QAction *actionSave_Tracts_in_MNI_space;
    QAction *actionOpen_Clusters;
    QAction *actionSave_Clusters;
    QAction *actionOpen_Cluster_Labels;
    QAction *actionSave_All_Tracts_As;
    QAction *actionSave_Left_Right_3D_Image;
    QAction *actionOpen_Subject_Data;
    QWidget *centralwidget;
    QVBoxLayout *centralLayout;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_3;
    QComboBox *SliceModality;
    QToolButton *addSlices;
    QToolButton *deleteSlice;
    QToolButton *isosurfaceButton;
    QComboBox *surfaceStyle;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *centralLayout2;
    QCheckBox *glSagCheck;
    QToolButton *glSagView;
    QSpinBox *glSagBox;
    QSlider *glSagSlider;
    QCheckBox *glCorCheck;
    QToolButton *glCorView;
    QSpinBox *glCorBox;
    QSlider *glCorSlider;
    QCheckBox *glAxiCheck;
    QToolButton *glAxiView;
    QSpinBox *glAxiBox;
    QSlider *glAxiSlider;
    QStatusBar *statusbar;
    QDockWidget *regionDockWidget;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_16;
    QToolButton *tbNewRegion;
    QToolButton *tbOpenRegion;
    QToolButton *tbSaveRegion;
    QToolButton *tbDeleteRegion;
    QToolButton *whole_brain;
    QFrame *line_5;
    QComboBox *atlasListBox;
    QComboBox *atlasComboBox;
    QToolButton *addRegionFromAtlas;
    QSpacerItem *horizontalSpacer_5;
    QDockWidget *renderingWidgetHolder;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *renderingLayout;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QToolButton *tbDefaultParam;
    QComboBox *RenderingQualityBox;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QMenu *menuRegions;
    QMenu *menuModify;
    QMenu *menuTracts;
    QMenu *menuSave;
    QMenu *menuClustering;
    QMenu *menuExport_Tract_Density;
    QMenu *menu_Edit;
    QMenu *menu_View;
    QMenu *menu_Slices;
    QMenu *menuConnectometry;
    QDockWidget *TractWidgetHolder;
    QWidget *dockWidgetContents_5;
    QVBoxLayout *tractverticalLayout;
    QHBoxLayout *horizontalLayout_15;
    QFrame *line_9;
    QToolButton *tbOpenTract;
    QToolButton *tbSaveTract;
    QToolButton *tbDeleteTract;
    QSpacerItem *horizontalSpacer_4;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QFrame *line;
    QToolButton *zoomIn;
    QToolButton *zoomOut;
    QFrame *line_4;
    QFrame *line_3;
    QToolButton *tool0;
    QToolButton *tool1;
    QToolButton *tool4;
    QToolButton *tool2;
    QToolButton *tool3;
    QToolButton *tool5;
    QFrame *line_2;
    QComboBox *view_style;
    QComboBox *sliceViewBox;
    QComboBox *overlay;
    QHBoxLayout *horizontalLayout_4;
    QFrame *line_7;
    QCheckBox *show_fiber;
    QCheckBox *show_pos;
    QFrame *line_6;
    QLabel *label_6;
    QSlider *contrast;
    QFrame *line_8;
    QLabel *label_8;
    QSlider *offset;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *SagView;
    QSlider *SagSlider;
    QToolButton *CorView;
    QSlider *CorSlider;
    QToolButton *AxiView;
    QSlider *AxiSlider;
    QDockWidget *dockWidget_3;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_9;
    QComboBox *tracking_index;
    QDoubleSpinBox *fa_threshold;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QSpinBox *turning_angle;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QDoubleSpinBox *step_size;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_4;
    QDoubleSpinBox *smoothing;
    QHBoxLayout *length_constraint_layout;
    QLabel *label_7;
    QDoubleSpinBox *min_length;
    QDoubleSpinBox *max_length;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *initial_direction;
    QComboBox *seed_plan;
    QComboBox *interpolation;
    QComboBox *tracking_method;
    QHBoxLayout *horizontalLayout_5;
    QSpinBox *track_count;
    QComboBox *tracking_plan;
    QComboBox *thread_count;
    QPushButton *perform_tracking;
    QToolButton *stopTracking;
    QDockWidget *dockWidget_report;
    QWidget *dockWidgetContents_6;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_14;
    QComboBox *report_index;
    QComboBox *profile_dir;
    QLabel *label;
    QDoubleSpinBox *report_bandwidth;
    QPushButton *refresh_report;
    QToolButton *save_report;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_12;
    QSpinBox *linewidth;
    QCheckBox *report_legend;
    QSpacerItem *horizontalSpacer_6;
    QCustomPlot *report_widget;
    QDockWidget *color_bar;
    QWidget *dockWidgetContents_7;
    QVBoxLayout *verticalLayout_7;
    QSplitter *splitter_2;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label_13;
    QComboBox *tract_color_index;
    QLabel *label_10;
    QComboBox *color_bar_style;
    QLabel *label_9;
    QDoubleSpinBox *tract_color_max_value;
    QLabel *label_15;
    QDoubleSpinBox *tract_color_min_value;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_17;
    QColorToolButton *color_from;
    QColorToolButton *color_to;
    QPushButton *update_rendering;
    QGraphicsView *color_bar_view;
    QDockWidget *vbc_widget;
    QWidget *dockWidgetContents_8;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_20;
    QToolButton *vbc_open_subject;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_21;
    QCustomPlot *vbc_report;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_6;
    QSplitter *splitter;
    QGraphicsView *vbc_view;
    QTableWidget *subject_list;

    void setupUi(QMainWindow *tracking_window)
    {
        if (tracking_window->objectName().isEmpty())
            tracking_window->setObjectName(QString::fromUtf8("tracking_window"));
        tracking_window->resize(1481, 667);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tracking_window->sizePolicy().hasHeightForWidth());
        tracking_window->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        tracking_window->setFont(font);
        tracking_window->setMouseTracking(false);
        actionNewRegion = new QAction(tracking_window);
        actionNewRegion->setObjectName(QString::fromUtf8("actionNewRegion"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/new.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewRegion->setIcon(icon);
        actionOpenRegion = new QAction(tracking_window);
        actionOpenRegion->setObjectName(QString::fromUtf8("actionOpenRegion"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/icons/open.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenRegion->setIcon(icon1);
        actionSaveRegionAs = new QAction(tracking_window);
        actionSaveRegionAs->setObjectName(QString::fromUtf8("actionSaveRegionAs"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/icons/save.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveRegionAs->setIcon(icon2);
        actionDeleteRegion = new QAction(tracking_window);
        actionDeleteRegion->setObjectName(QString::fromUtf8("actionDeleteRegion"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/icons/delete.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeleteRegion->setIcon(icon3);
        actionDeleteRegion->setFont(font);
        actionOpenTract = new QAction(tracking_window);
        actionOpenTract->setObjectName(QString::fromUtf8("actionOpenTract"));
        actionOpenTract->setIcon(icon1);
        actionOpenTract->setFont(font);
        actionSaveTractAs = new QAction(tracking_window);
        actionSaveTractAs->setObjectName(QString::fromUtf8("actionSaveTractAs"));
        actionSaveTractAs->setIcon(icon2);
        actionSaveTractAs->setFont(font);
        actionSaveTractFA = new QAction(tracking_window);
        actionSaveTractFA->setObjectName(QString::fromUtf8("actionSaveTractFA"));
        actionSaveTractFA->setIcon(icon2);
        actionSaveTractFA->setFont(font);
        actionDeleteRegionAll = new QAction(tracking_window);
        actionDeleteRegionAll->setObjectName(QString::fromUtf8("actionDeleteRegionAll"));
        actionDeleteRegionAll->setIcon(icon3);
        actionDeleteRegionAll->setFont(font);
        actionDeleteTract = new QAction(tracking_window);
        actionDeleteTract->setObjectName(QString::fromUtf8("actionDeleteTract"));
        actionDeleteTract->setIcon(icon3);
        actionDeleteTract->setFont(font);
        actionDeleteTractAll = new QAction(tracking_window);
        actionDeleteTractAll->setObjectName(QString::fromUtf8("actionDeleteTractAll"));
        actionDeleteTractAll->setIcon(icon3);
        actionDeleteTractAll->setFont(font);
        actionShift_X = new QAction(tracking_window);
        actionShift_X->setObjectName(QString::fromUtf8("actionShift_X"));
        actionShift_X_2 = new QAction(tracking_window);
        actionShift_X_2->setObjectName(QString::fromUtf8("actionShift_X_2"));
        actionShift_Y = new QAction(tracking_window);
        actionShift_Y->setObjectName(QString::fromUtf8("actionShift_Y"));
        actionShift_Y_2 = new QAction(tracking_window);
        actionShift_Y_2->setObjectName(QString::fromUtf8("actionShift_Y_2"));
        actionShift_Z = new QAction(tracking_window);
        actionShift_Z->setObjectName(QString::fromUtf8("actionShift_Z"));
        actionShift_Z_2 = new QAction(tracking_window);
        actionShift_Z_2->setObjectName(QString::fromUtf8("actionShift_Z_2"));
        actionFlip_X = new QAction(tracking_window);
        actionFlip_X->setObjectName(QString::fromUtf8("actionFlip_X"));
        actionFlip_Y = new QAction(tracking_window);
        actionFlip_Y->setObjectName(QString::fromUtf8("actionFlip_Y"));
        actionFlip_Z = new QAction(tracking_window);
        actionFlip_Z->setObjectName(QString::fromUtf8("actionFlip_Z"));
        actionDilation = new QAction(tracking_window);
        actionDilation->setObjectName(QString::fromUtf8("actionDilation"));
        actionErosion = new QAction(tracking_window);
        actionErosion->setObjectName(QString::fromUtf8("actionErosion"));
        actionSmoothing = new QAction(tracking_window);
        actionSmoothing->setObjectName(QString::fromUtf8("actionSmoothing"));
        actionNegate = new QAction(tracking_window);
        actionNegate->setObjectName(QString::fromUtf8("actionNegate"));
        actionDefragment = new QAction(tracking_window);
        actionDefragment->setObjectName(QString::fromUtf8("actionDefragment"));
        actionWhole_brain_seeding = new QAction(tracking_window);
        actionWhole_brain_seeding->setObjectName(QString::fromUtf8("actionWhole_brain_seeding"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/icons/axial.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        actionWhole_brain_seeding->setIcon(icon4);
        actionSelect_Tracts = new QAction(tracking_window);
        actionSelect_Tracts->setObjectName(QString::fromUtf8("actionSelect_Tracts"));
        actionUndo = new QAction(tracking_window);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionDelete = new QAction(tracking_window);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        actionTrim = new QAction(tracking_window);
        actionTrim->setObjectName(QString::fromUtf8("actionTrim"));
        actionCut = new QAction(tracking_window);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionZoom_In = new QAction(tracking_window);
        actionZoom_In->setObjectName(QString::fromUtf8("actionZoom_In"));
        actionZoom_Out = new QAction(tracking_window);
        actionZoom_Out->setObjectName(QString::fromUtf8("actionZoom_Out"));
        actionSagittal_view = new QAction(tracking_window);
        actionSagittal_view->setObjectName(QString::fromUtf8("actionSagittal_view"));
        actionCoronal_View = new QAction(tracking_window);
        actionCoronal_View->setObjectName(QString::fromUtf8("actionCoronal_View"));
        actionAxial_View = new QAction(tracking_window);
        actionAxial_View->setObjectName(QString::fromUtf8("actionAxial_View"));
        actionQuantitative_anisotropy_QA = new QAction(tracking_window);
        actionQuantitative_anisotropy_QA->setObjectName(QString::fromUtf8("actionQuantitative_anisotropy_QA"));
        actionMerge_All = new QAction(tracking_window);
        actionMerge_All->setObjectName(QString::fromUtf8("actionMerge_All"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/icons/add.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        actionMerge_All->setIcon(icon5);
        actionSave_Screen = new QAction(tracking_window);
        actionSave_Screen->setObjectName(QString::fromUtf8("actionSave_Screen"));
        actionSave_Screen->setIcon(icon2);
        actionSave_ROI_Screen = new QAction(tracking_window);
        actionSave_ROI_Screen->setObjectName(QString::fromUtf8("actionSave_ROI_Screen"));
        actionSave_ROI_Screen->setIcon(icon2);
        actionLoad_Camera = new QAction(tracking_window);
        actionLoad_Camera->setObjectName(QString::fromUtf8("actionLoad_Camera"));
        actionLoad_Camera->setIcon(icon1);
        actionSave_Camera = new QAction(tracking_window);
        actionSave_Camera->setObjectName(QString::fromUtf8("actionSave_Camera"));
        actionSave_Camera->setIcon(icon2);
        actionEndpoints_to_seeding = new QAction(tracking_window);
        actionEndpoints_to_seeding->setObjectName(QString::fromUtf8("actionEndpoints_to_seeding"));
        actionTracts_to_seeds = new QAction(tracking_window);
        actionTracts_to_seeds->setObjectName(QString::fromUtf8("actionTracts_to_seeds"));
        actionSave_Rotation_Images = new QAction(tracking_window);
        actionSave_Rotation_Images->setObjectName(QString::fromUtf8("actionSave_Rotation_Images"));
        actionSave_Rotation_Images->setIcon(icon2);
        actionPaint = new QAction(tracking_window);
        actionPaint->setObjectName(QString::fromUtf8("actionPaint"));
        actionInsert_T1_T2 = new QAction(tracking_window);
        actionInsert_T1_T2->setObjectName(QString::fromUtf8("actionInsert_T1_T2"));
        actionInsert_T1_T2->setIcon(icon1);
        actionAdd_surface = new QAction(tracking_window);
        actionAdd_surface->setObjectName(QString::fromUtf8("actionAdd_surface"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icons/icons/coronal.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_surface->setIcon(icon6);
        actionSave_mapping = new QAction(tracking_window);
        actionSave_mapping->setObjectName(QString::fromUtf8("actionSave_mapping"));
        actionSave_mapping->setIcon(icon2);
        actionLoad_mapping = new QAction(tracking_window);
        actionLoad_mapping->setObjectName(QString::fromUtf8("actionLoad_mapping"));
        actionLoad_mapping->setIcon(icon1);
        actionStatistics = new QAction(tracking_window);
        actionStatistics->setObjectName(QString::fromUtf8("actionStatistics"));
        actionK_means = new QAction(tracking_window);
        actionK_means->setObjectName(QString::fromUtf8("actionK_means"));
        actionEM = new QAction(tracking_window);
        actionEM->setObjectName(QString::fromUtf8("actionEM"));
        actionHierarchical = new QAction(tracking_window);
        actionHierarchical->setObjectName(QString::fromUtf8("actionHierarchical"));
        actionSet_Color = new QAction(tracking_window);
        actionSet_Color->setObjectName(QString::fromUtf8("actionSet_Color"));
        actionSave_Tracts_Colors_As = new QAction(tracking_window);
        actionSave_Tracts_Colors_As->setObjectName(QString::fromUtf8("actionSave_Tracts_Colors_As"));
        actionSave_Tracts_Colors_As->setIcon(icon2);
        actionOpen_Colors = new QAction(tracking_window);
        actionOpen_Colors->setObjectName(QString::fromUtf8("actionOpen_Colors"));
        actionOpen_Colors->setIcon(icon1);
        actionSave_Voxel_Data_As = new QAction(tracking_window);
        actionSave_Voxel_Data_As->setObjectName(QString::fromUtf8("actionSave_Voxel_Data_As"));
        actionSave_Voxel_Data_As->setIcon(icon2);
        actionTDI_Diffusion_Space = new QAction(tracking_window);
        actionTDI_Diffusion_Space->setObjectName(QString::fromUtf8("actionTDI_Diffusion_Space"));
        actionTDI_Diffusion_Space->setIcon(icon2);
        actionTDI_Import_Slice_Space = new QAction(tracking_window);
        actionTDI_Import_Slice_Space->setObjectName(QString::fromUtf8("actionTDI_Import_Slice_Space"));
        actionTDI_Import_Slice_Space->setIcon(icon2);
        actionTDI_Subvoxel_Diffusion_Space = new QAction(tracking_window);
        actionTDI_Subvoxel_Diffusion_Space->setObjectName(QString::fromUtf8("actionTDI_Subvoxel_Diffusion_Space"));
        actionTDI_Subvoxel_Diffusion_Space->setIcon(icon2);
        actionSave_Tracts_in_Current_Mapping = new QAction(tracking_window);
        actionSave_Tracts_in_Current_Mapping->setObjectName(QString::fromUtf8("actionSave_Tracts_in_Current_Mapping"));
        actionSave_Tracts_in_Current_Mapping->setIcon(icon2);
        actionThreshold = new QAction(tracking_window);
        actionThreshold->setObjectName(QString::fromUtf8("actionThreshold"));
        actionRedo = new QAction(tracking_window);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionCopy_to_clipboard = new QAction(tracking_window);
        actionCopy_to_clipboard->setObjectName(QString::fromUtf8("actionCopy_to_clipboard"));
        actionSave_Anisotrpy_Map_as = new QAction(tracking_window);
        actionSave_Anisotrpy_Map_as->setObjectName(QString::fromUtf8("actionSave_Anisotrpy_Map_as"));
        actionSave_Anisotrpy_Map_as->setIcon(icon2);
        actionRestore_window_layout = new QAction(tracking_window);
        actionRestore_window_layout->setObjectName(QString::fromUtf8("actionRestore_window_layout"));
        actionSave_Endpoints_in_Current_Mapping = new QAction(tracking_window);
        actionSave_Endpoints_in_Current_Mapping->setObjectName(QString::fromUtf8("actionSave_Endpoints_in_Current_Mapping"));
        actionSave_Endpoints_in_Current_Mapping->setIcon(icon2);
        actionMove_Object = new QAction(tracking_window);
        actionMove_Object->setObjectName(QString::fromUtf8("actionMove_Object"));
        actionSave_Report_as = new QAction(tracking_window);
        actionSave_Report_as->setObjectName(QString::fromUtf8("actionSave_Report_as"));
        actionSave_Report_as->setIcon(icon2);
        actionSave_Tracts_in_MNI_space = new QAction(tracking_window);
        actionSave_Tracts_in_MNI_space->setObjectName(QString::fromUtf8("actionSave_Tracts_in_MNI_space"));
        actionSave_Tracts_in_MNI_space->setIcon(icon2);
        actionOpen_Clusters = new QAction(tracking_window);
        actionOpen_Clusters->setObjectName(QString::fromUtf8("actionOpen_Clusters"));
        actionOpen_Clusters->setIcon(icon1);
        actionSave_Clusters = new QAction(tracking_window);
        actionSave_Clusters->setObjectName(QString::fromUtf8("actionSave_Clusters"));
        actionSave_Clusters->setIcon(icon2);
        actionOpen_Cluster_Labels = new QAction(tracking_window);
        actionOpen_Cluster_Labels->setObjectName(QString::fromUtf8("actionOpen_Cluster_Labels"));
        actionOpen_Cluster_Labels->setIcon(icon1);
        actionSave_All_Tracts_As = new QAction(tracking_window);
        actionSave_All_Tracts_As->setObjectName(QString::fromUtf8("actionSave_All_Tracts_As"));
        actionSave_All_Tracts_As->setIcon(icon2);
        actionSave_Left_Right_3D_Image = new QAction(tracking_window);
        actionSave_Left_Right_3D_Image->setObjectName(QString::fromUtf8("actionSave_Left_Right_3D_Image"));
        actionSave_Left_Right_3D_Image->setIcon(icon2);
        actionOpen_Subject_Data = new QAction(tracking_window);
        actionOpen_Subject_Data->setObjectName(QString::fromUtf8("actionOpen_Subject_Data"));
        actionOpen_Subject_Data->setIcon(icon1);
        centralwidget = new QWidget(tracking_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralLayout = new QVBoxLayout(centralwidget);
        centralLayout->setSpacing(0);
        centralLayout->setContentsMargins(0, 0, 0, 0);
        centralLayout->setObjectName(QString::fromUtf8("centralLayout"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_13->addWidget(label_3);

        SliceModality = new QComboBox(centralwidget);
        SliceModality->setObjectName(QString::fromUtf8("SliceModality"));
        SliceModality->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_13->addWidget(SliceModality);

        addSlices = new QToolButton(centralwidget);
        addSlices->setObjectName(QString::fromUtf8("addSlices"));
        addSlices->setMaximumSize(QSize(24, 22));
        addSlices->setIcon(icon1);
        addSlices->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_13->addWidget(addSlices);

        deleteSlice = new QToolButton(centralwidget);
        deleteSlice->setObjectName(QString::fromUtf8("deleteSlice"));
        deleteSlice->setMaximumSize(QSize(24, 22));
        deleteSlice->setIcon(icon3);

        horizontalLayout_13->addWidget(deleteSlice);

        isosurfaceButton = new QToolButton(centralwidget);
        isosurfaceButton->setObjectName(QString::fromUtf8("isosurfaceButton"));

        horizontalLayout_13->addWidget(isosurfaceButton);

        surfaceStyle = new QComboBox(centralwidget);
        surfaceStyle->setObjectName(QString::fromUtf8("surfaceStyle"));
        surfaceStyle->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_13->addWidget(surfaceStyle);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);


        centralLayout->addLayout(horizontalLayout_13);

        centralLayout2 = new QHBoxLayout();
        centralLayout2->setSpacing(0);
        centralLayout2->setObjectName(QString::fromUtf8("centralLayout2"));
        glSagCheck = new QCheckBox(centralwidget);
        glSagCheck->setObjectName(QString::fromUtf8("glSagCheck"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(glSagCheck->sizePolicy().hasHeightForWidth());
        glSagCheck->setSizePolicy(sizePolicy1);
        glSagCheck->setMinimumSize(QSize(16, 0));

        centralLayout2->addWidget(glSagCheck);

        glSagView = new QToolButton(centralwidget);
        glSagView->setObjectName(QString::fromUtf8("glSagView"));
        glSagView->setMaximumSize(QSize(22, 22));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icons/icons/sag.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        glSagView->setIcon(icon7);

        centralLayout2->addWidget(glSagView);

        glSagBox = new QSpinBox(centralwidget);
        glSagBox->setObjectName(QString::fromUtf8("glSagBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(glSagBox->sizePolicy().hasHeightForWidth());
        glSagBox->setSizePolicy(sizePolicy2);

        centralLayout2->addWidget(glSagBox);

        glSagSlider = new QSlider(centralwidget);
        glSagSlider->setObjectName(QString::fromUtf8("glSagSlider"));
        glSagSlider->setOrientation(Qt::Horizontal);

        centralLayout2->addWidget(glSagSlider);

        glCorCheck = new QCheckBox(centralwidget);
        glCorCheck->setObjectName(QString::fromUtf8("glCorCheck"));
        sizePolicy1.setHeightForWidth(glCorCheck->sizePolicy().hasHeightForWidth());
        glCorCheck->setSizePolicy(sizePolicy1);
        glCorCheck->setMinimumSize(QSize(16, 0));

        centralLayout2->addWidget(glCorCheck);

        glCorView = new QToolButton(centralwidget);
        glCorView->setObjectName(QString::fromUtf8("glCorView"));
        glCorView->setMaximumSize(QSize(22, 22));
        glCorView->setIcon(icon6);

        centralLayout2->addWidget(glCorView);

        glCorBox = new QSpinBox(centralwidget);
        glCorBox->setObjectName(QString::fromUtf8("glCorBox"));
        sizePolicy2.setHeightForWidth(glCorBox->sizePolicy().hasHeightForWidth());
        glCorBox->setSizePolicy(sizePolicy2);

        centralLayout2->addWidget(glCorBox);

        glCorSlider = new QSlider(centralwidget);
        glCorSlider->setObjectName(QString::fromUtf8("glCorSlider"));
        glCorSlider->setOrientation(Qt::Horizontal);

        centralLayout2->addWidget(glCorSlider);

        glAxiCheck = new QCheckBox(centralwidget);
        glAxiCheck->setObjectName(QString::fromUtf8("glAxiCheck"));
        sizePolicy1.setHeightForWidth(glAxiCheck->sizePolicy().hasHeightForWidth());
        glAxiCheck->setSizePolicy(sizePolicy1);
        glAxiCheck->setMinimumSize(QSize(16, 0));

        centralLayout2->addWidget(glAxiCheck);

        glAxiView = new QToolButton(centralwidget);
        glAxiView->setObjectName(QString::fromUtf8("glAxiView"));
        glAxiView->setMinimumSize(QSize(0, 0));
        glAxiView->setMaximumSize(QSize(22, 22));
        glAxiView->setIcon(icon4);

        centralLayout2->addWidget(glAxiView);

        glAxiBox = new QSpinBox(centralwidget);
        glAxiBox->setObjectName(QString::fromUtf8("glAxiBox"));
        sizePolicy2.setHeightForWidth(glAxiBox->sizePolicy().hasHeightForWidth());
        glAxiBox->setSizePolicy(sizePolicy2);

        centralLayout2->addWidget(glAxiBox);

        glAxiSlider = new QSlider(centralwidget);
        glAxiSlider->setObjectName(QString::fromUtf8("glAxiSlider"));
        glAxiSlider->setOrientation(Qt::Horizontal);

        centralLayout2->addWidget(glAxiSlider);


        centralLayout->addLayout(centralLayout2);

        tracking_window->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(tracking_window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        tracking_window->setStatusBar(statusbar);
        regionDockWidget = new QDockWidget(tracking_window);
        regionDockWidget->setObjectName(QString::fromUtf8("regionDockWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(regionDockWidget->sizePolicy().hasHeightForWidth());
        regionDockWidget->setSizePolicy(sizePolicy3);
        regionDockWidget->setMinimumSize(QSize(311, 46));
        regionDockWidget->setMaximumSize(QSize(600, 524287));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        regionDockWidget->setFont(font1);
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(0);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        tbNewRegion = new QToolButton(dockWidgetContents_4);
        tbNewRegion->setObjectName(QString::fromUtf8("tbNewRegion"));
        tbNewRegion->setMaximumSize(QSize(23, 22));
        tbNewRegion->setIcon(icon);

        horizontalLayout_16->addWidget(tbNewRegion);

        tbOpenRegion = new QToolButton(dockWidgetContents_4);
        tbOpenRegion->setObjectName(QString::fromUtf8("tbOpenRegion"));
        tbOpenRegion->setMaximumSize(QSize(23, 22));
        tbOpenRegion->setIcon(icon1);

        horizontalLayout_16->addWidget(tbOpenRegion);

        tbSaveRegion = new QToolButton(dockWidgetContents_4);
        tbSaveRegion->setObjectName(QString::fromUtf8("tbSaveRegion"));
        tbSaveRegion->setMaximumSize(QSize(23, 22));
        tbSaveRegion->setIcon(icon2);

        horizontalLayout_16->addWidget(tbSaveRegion);

        tbDeleteRegion = new QToolButton(dockWidgetContents_4);
        tbDeleteRegion->setObjectName(QString::fromUtf8("tbDeleteRegion"));
        tbDeleteRegion->setMaximumSize(QSize(23, 22));
        tbDeleteRegion->setIcon(icon3);

        horizontalLayout_16->addWidget(tbDeleteRegion);

        whole_brain = new QToolButton(dockWidgetContents_4);
        whole_brain->setObjectName(QString::fromUtf8("whole_brain"));
        sizePolicy1.setHeightForWidth(whole_brain->sizePolicy().hasHeightForWidth());
        whole_brain->setSizePolicy(sizePolicy1);
        whole_brain->setMaximumSize(QSize(23, 22));
        whole_brain->setIcon(icon4);

        horizontalLayout_16->addWidget(whole_brain);

        line_5 = new QFrame(dockWidgetContents_4);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_16->addWidget(line_5);

        atlasListBox = new QComboBox(dockWidgetContents_4);
        atlasListBox->setObjectName(QString::fromUtf8("atlasListBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(atlasListBox->sizePolicy().hasHeightForWidth());
        atlasListBox->setSizePolicy(sizePolicy4);
        atlasListBox->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_16->addWidget(atlasListBox);

        atlasComboBox = new QComboBox(dockWidgetContents_4);
        atlasComboBox->setObjectName(QString::fromUtf8("atlasComboBox"));
        sizePolicy4.setHeightForWidth(atlasComboBox->sizePolicy().hasHeightForWidth());
        atlasComboBox->setSizePolicy(sizePolicy4);
        atlasComboBox->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_16->addWidget(atlasComboBox);

        addRegionFromAtlas = new QToolButton(dockWidgetContents_4);
        addRegionFromAtlas->setObjectName(QString::fromUtf8("addRegionFromAtlas"));
        addRegionFromAtlas->setMaximumSize(QSize(16777215, 22));
        addRegionFromAtlas->setIcon(icon5);
        addRegionFromAtlas->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_16->addWidget(addRegionFromAtlas);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_16);

        regionDockWidget->setWidget(dockWidgetContents_4);
        tracking_window->addDockWidget(static_cast<Qt::DockWidgetArea>(1), regionDockWidget);
        renderingWidgetHolder = new QDockWidget(tracking_window);
        renderingWidgetHolder->setObjectName(QString::fromUtf8("renderingWidgetHolder"));
        sizePolicy.setHeightForWidth(renderingWidgetHolder->sizePolicy().hasHeightForWidth());
        renderingWidgetHolder->setSizePolicy(sizePolicy);
        renderingWidgetHolder->setMinimumSize(QSize(232, 48));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        renderingLayout = new QVBoxLayout(dockWidgetContents_2);
        renderingLayout->setSpacing(0);
        renderingLayout->setContentsMargins(0, 0, 0, 0);
        renderingLayout->setObjectName(QString::fromUtf8("renderingLayout"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        tbDefaultParam = new QToolButton(dockWidgetContents_2);
        tbDefaultParam->setObjectName(QString::fromUtf8("tbDefaultParam"));

        horizontalLayout_6->addWidget(tbDefaultParam);

        RenderingQualityBox = new QComboBox(dockWidgetContents_2);
        RenderingQualityBox->setObjectName(QString::fromUtf8("RenderingQualityBox"));
        RenderingQualityBox->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_6->addWidget(RenderingQualityBox);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        horizontalLayout_8->addLayout(horizontalLayout_6);


        renderingLayout->addLayout(horizontalLayout_8);

        renderingWidgetHolder->setWidget(dockWidgetContents_2);
        tracking_window->addDockWidget(static_cast<Qt::DockWidgetArea>(2), renderingWidgetHolder);
        menuBar = new QMenuBar(tracking_window);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1481, 21));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy5);
        menuBar->setFont(font);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(false);
        menuRegions = new QMenu(menuBar);
        menuRegions->setObjectName(QString::fromUtf8("menuRegions"));
        menuModify = new QMenu(menuRegions);
        menuModify->setObjectName(QString::fromUtf8("menuModify"));
        menuTracts = new QMenu(menuBar);
        menuTracts->setObjectName(QString::fromUtf8("menuTracts"));
        menuSave = new QMenu(menuTracts);
        menuSave->setObjectName(QString::fromUtf8("menuSave"));
        menuClustering = new QMenu(menuTracts);
        menuClustering->setObjectName(QString::fromUtf8("menuClustering"));
        menuExport_Tract_Density = new QMenu(menuTracts);
        menuExport_Tract_Density->setObjectName(QString::fromUtf8("menuExport_Tract_Density"));
        menu_Edit = new QMenu(menuBar);
        menu_Edit->setObjectName(QString::fromUtf8("menu_Edit"));
        menu_View = new QMenu(menuBar);
        menu_View->setObjectName(QString::fromUtf8("menu_View"));
        menu_Slices = new QMenu(menuBar);
        menu_Slices->setObjectName(QString::fromUtf8("menu_Slices"));
        menuConnectometry = new QMenu(menuBar);
        menuConnectometry->setObjectName(QString::fromUtf8("menuConnectometry"));
        tracking_window->setMenuBar(menuBar);
        TractWidgetHolder = new QDockWidget(tracking_window);
        TractWidgetHolder->setObjectName(QString::fromUtf8("TractWidgetHolder"));
        sizePolicy.setHeightForWidth(TractWidgetHolder->sizePolicy().hasHeightForWidth());
        TractWidgetHolder->setSizePolicy(sizePolicy);
        TractWidgetHolder->setMinimumSize(QSize(80, 46));
        TractWidgetHolder->setMaximumSize(QSize(524287, 524287));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        tractverticalLayout = new QVBoxLayout(dockWidgetContents_5);
        tractverticalLayout->setSpacing(0);
        tractverticalLayout->setContentsMargins(0, 0, 0, 0);
        tractverticalLayout->setObjectName(QString::fromUtf8("tractverticalLayout"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(0);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        line_9 = new QFrame(dockWidgetContents_5);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);

        horizontalLayout_15->addWidget(line_9);

        tbOpenTract = new QToolButton(dockWidgetContents_5);
        tbOpenTract->setObjectName(QString::fromUtf8("tbOpenTract"));
        tbOpenTract->setMaximumSize(QSize(23, 22));
        tbOpenTract->setIcon(icon1);

        horizontalLayout_15->addWidget(tbOpenTract);

        tbSaveTract = new QToolButton(dockWidgetContents_5);
        tbSaveTract->setObjectName(QString::fromUtf8("tbSaveTract"));
        tbSaveTract->setMaximumSize(QSize(23, 22));
        tbSaveTract->setIcon(icon2);

        horizontalLayout_15->addWidget(tbSaveTract);

        tbDeleteTract = new QToolButton(dockWidgetContents_5);
        tbDeleteTract->setObjectName(QString::fromUtf8("tbDeleteTract"));
        tbDeleteTract->setMaximumSize(QSize(23, 22));
        tbDeleteTract->setIcon(icon3);

        horizontalLayout_15->addWidget(tbDeleteTract);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_4);


        tractverticalLayout->addLayout(horizontalLayout_15);

        TractWidgetHolder->setWidget(dockWidgetContents_5);
        tracking_window->addDockWidget(static_cast<Qt::DockWidgetArea>(2), TractWidgetHolder);
        dockWidget = new QDockWidget(tracking_window);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(1);
        sizePolicy6.setHeightForWidth(dockWidget->sizePolicy().hasHeightForWidth());
        dockWidget->setSizePolicy(sizePolicy6);
        dockWidget->setMinimumSize(QSize(423, 162));
        dockWidget->setFloating(false);
        dockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        line = new QFrame(dockWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line);

        zoomIn = new QToolButton(dockWidgetContents);
        zoomIn->setObjectName(QString::fromUtf8("zoomIn"));
        zoomIn->setMinimumSize(QSize(22, 0));
        zoomIn->setMaximumSize(QSize(23, 22));

        horizontalLayout_7->addWidget(zoomIn);

        zoomOut = new QToolButton(dockWidgetContents);
        zoomOut->setObjectName(QString::fromUtf8("zoomOut"));
        zoomOut->setMinimumSize(QSize(22, 0));
        zoomOut->setMaximumSize(QSize(23, 22));

        horizontalLayout_7->addWidget(zoomOut);

        line_4 = new QFrame(dockWidgetContents);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_4);

        line_3 = new QFrame(dockWidgetContents);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_3);

        tool0 = new QToolButton(dockWidgetContents);
        tool0->setObjectName(QString::fromUtf8("tool0"));
        tool0->setMaximumSize(QSize(23, 22));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icons/icons/rec.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        tool0->setIcon(icon8);
        tool0->setIconSize(QSize(16, 16));
        tool0->setCheckable(true);
        tool0->setChecked(true);
        tool0->setAutoExclusive(true);

        horizontalLayout_7->addWidget(tool0);

        tool1 = new QToolButton(dockWidgetContents);
        tool1->setObjectName(QString::fromUtf8("tool1"));
        tool1->setMaximumSize(QSize(23, 22));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icons/icons/curves.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        tool1->setIcon(icon9);
        tool1->setIconSize(QSize(16, 16));
        tool1->setCheckable(true);
        tool1->setChecked(false);
        tool1->setAutoExclusive(true);

        horizontalLayout_7->addWidget(tool1);

        tool4 = new QToolButton(dockWidgetContents);
        tool4->setObjectName(QString::fromUtf8("tool4"));
        tool4->setMaximumSize(QSize(23, 22));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icons/icons/poly.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        tool4->setIcon(icon10);
        tool4->setCheckable(true);
        tool4->setAutoExclusive(true);

        horizontalLayout_7->addWidget(tool4);

        tool2 = new QToolButton(dockWidgetContents);
        tool2->setObjectName(QString::fromUtf8("tool2"));
        tool2->setMaximumSize(QSize(23, 22));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icons/icons/ball.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        tool2->setIcon(icon11);
        tool2->setIconSize(QSize(16, 16));
        tool2->setCheckable(true);
        tool2->setAutoExclusive(true);

        horizontalLayout_7->addWidget(tool2);

        tool3 = new QToolButton(dockWidgetContents);
        tool3->setObjectName(QString::fromUtf8("tool3"));
        tool3->setMaximumSize(QSize(23, 22));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icons/icons/cubic.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        tool3->setIcon(icon12);
        tool3->setIconSize(QSize(16, 16));
        tool3->setCheckable(true);
        tool3->setAutoExclusive(true);

        horizontalLayout_7->addWidget(tool3);

        tool5 = new QToolButton(dockWidgetContents);
        tool5->setObjectName(QString::fromUtf8("tool5"));
        tool5->setMaximumSize(QSize(23, 22));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/icons/icons/move.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        tool5->setIcon(icon13);
        tool5->setCheckable(true);
        tool5->setAutoExclusive(true);

        horizontalLayout_7->addWidget(tool5);

        line_2 = new QFrame(dockWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_2);

        view_style = new QComboBox(dockWidgetContents);
        view_style->setObjectName(QString::fromUtf8("view_style"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(view_style->sizePolicy().hasHeightForWidth());
        view_style->setSizePolicy(sizePolicy7);
        view_style->setMaximumSize(QSize(6666, 22));

        horizontalLayout_7->addWidget(view_style);

        sliceViewBox = new QComboBox(dockWidgetContents);
        sliceViewBox->setObjectName(QString::fromUtf8("sliceViewBox"));
        sizePolicy7.setHeightForWidth(sliceViewBox->sizePolicy().hasHeightForWidth());
        sliceViewBox->setSizePolicy(sizePolicy7);
        sliceViewBox->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_7->addWidget(sliceViewBox);

        overlay = new QComboBox(dockWidgetContents);
        overlay->setObjectName(QString::fromUtf8("overlay"));
        sizePolicy7.setHeightForWidth(overlay->sizePolicy().hasHeightForWidth());
        overlay->setSizePolicy(sizePolicy7);
        overlay->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_7->addWidget(overlay);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, 0, -1, -1);
        line_7 = new QFrame(dockWidgetContents);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_7);

        show_fiber = new QCheckBox(dockWidgetContents);
        show_fiber->setObjectName(QString::fromUtf8("show_fiber"));
        sizePolicy2.setHeightForWidth(show_fiber->sizePolicy().hasHeightForWidth());
        show_fiber->setSizePolicy(sizePolicy2);
        show_fiber->setChecked(true);

        horizontalLayout_4->addWidget(show_fiber);

        show_pos = new QCheckBox(dockWidgetContents);
        show_pos->setObjectName(QString::fromUtf8("show_pos"));
        show_pos->setChecked(true);

        horizontalLayout_4->addWidget(show_pos);

        line_6 = new QFrame(dockWidgetContents);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_6);

        label_6 = new QLabel(dockWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy8(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy8);

        horizontalLayout_4->addWidget(label_6);

        contrast = new QSlider(dockWidgetContents);
        contrast->setObjectName(QString::fromUtf8("contrast"));
        sizePolicy4.setHeightForWidth(contrast->sizePolicy().hasHeightForWidth());
        contrast->setSizePolicy(sizePolicy4);
        contrast->setMinimum(100);
        contrast->setMaximum(500);
        contrast->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(contrast);

        line_8 = new QFrame(dockWidgetContents);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_8);

        label_8 = new QLabel(dockWidgetContents);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy8.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy8);

        horizontalLayout_4->addWidget(label_8);

        offset = new QSlider(dockWidgetContents);
        offset->setObjectName(QString::fromUtf8("offset"));
        sizePolicy4.setHeightForWidth(offset->sizePolicy().hasHeightForWidth());
        offset->setSizePolicy(sizePolicy4);
        offset->setMinimum(-100);
        offset->setMaximum(100);
        offset->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(offset);


        verticalLayout->addLayout(horizontalLayout_4);

        graphicsView = new QGraphicsView(dockWidgetContents);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        SagView = new QToolButton(dockWidgetContents);
        SagView->setObjectName(QString::fromUtf8("SagView"));
        SagView->setMaximumSize(QSize(23, 22));
        SagView->setIcon(icon7);

        horizontalLayout_2->addWidget(SagView);

        SagSlider = new QSlider(dockWidgetContents);
        SagSlider->setObjectName(QString::fromUtf8("SagSlider"));
        SagSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(SagSlider);

        CorView = new QToolButton(dockWidgetContents);
        CorView->setObjectName(QString::fromUtf8("CorView"));
        CorView->setMaximumSize(QSize(23, 22));
        CorView->setIcon(icon6);

        horizontalLayout_2->addWidget(CorView);

        CorSlider = new QSlider(dockWidgetContents);
        CorSlider->setObjectName(QString::fromUtf8("CorSlider"));
        CorSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(CorSlider);

        AxiView = new QToolButton(dockWidgetContents);
        AxiView->setObjectName(QString::fromUtf8("AxiView"));
        AxiView->setMaximumSize(QSize(23, 22));
        AxiView->setIcon(icon4);

        horizontalLayout_2->addWidget(AxiView);

        AxiSlider = new QSlider(dockWidgetContents);
        AxiSlider->setObjectName(QString::fromUtf8("AxiSlider"));
        AxiSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(AxiSlider);


        verticalLayout->addLayout(horizontalLayout_2);

        dockWidget->setWidget(dockWidgetContents);
        tracking_window->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget);
        dockWidget_3 = new QDockWidget(tracking_window);
        dockWidget_3->setObjectName(QString::fromUtf8("dockWidget_3"));
        sizePolicy.setHeightForWidth(dockWidget_3->sizePolicy().hasHeightForWidth());
        dockWidget_3->setSizePolicy(sizePolicy);
        dockWidget_3->setMinimumSize(QSize(623, 150));
        dockWidget_3->setMaximumSize(QSize(65535, 150));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, -1, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(5, -1, -1, -1);
        tracking_index = new QComboBox(dockWidgetContents_3);
        tracking_index->setObjectName(QString::fromUtf8("tracking_index"));

        horizontalLayout_9->addWidget(tracking_index);

        fa_threshold = new QDoubleSpinBox(dockWidgetContents_3);
        fa_threshold->setObjectName(QString::fromUtf8("fa_threshold"));
        sizePolicy7.setHeightForWidth(fa_threshold->sizePolicy().hasHeightForWidth());
        fa_threshold->setSizePolicy(sizePolicy7);
        fa_threshold->setDecimals(5);
        fa_threshold->setMaximum(99.99);
        fa_threshold->setSingleStep(0.01);

        horizontalLayout_9->addWidget(fa_threshold);


        gridLayout->addLayout(horizontalLayout_9, 3, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, -1, -1, -1);
        label_2 = new QLabel(dockWidgetContents_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_10->addWidget(label_2);

        turning_angle = new QSpinBox(dockWidgetContents_3);
        turning_angle->setObjectName(QString::fromUtf8("turning_angle"));
        sizePolicy7.setHeightForWidth(turning_angle->sizePolicy().hasHeightForWidth());
        turning_angle->setSizePolicy(sizePolicy7);
        turning_angle->setMaximum(90);
        turning_angle->setSingleStep(5);
        turning_angle->setValue(60);

        horizontalLayout_10->addWidget(turning_angle);


        gridLayout->addLayout(horizontalLayout_10, 3, 1, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(5, -1, -1, -1);
        label_5 = new QLabel(dockWidgetContents_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_11->addWidget(label_5);

        step_size = new QDoubleSpinBox(dockWidgetContents_3);
        step_size->setObjectName(QString::fromUtf8("step_size"));
        sizePolicy7.setHeightForWidth(step_size->sizePolicy().hasHeightForWidth());
        step_size->setSizePolicy(sizePolicy7);
        step_size->setDecimals(3);
        step_size->setMinimum(0.001);
        step_size->setMaximum(100);
        step_size->setSingleStep(0.5);
        step_size->setValue(0.5);

        horizontalLayout_11->addWidget(step_size);


        gridLayout->addLayout(horizontalLayout_11, 10, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(5, -1, -1, -1);
        label_4 = new QLabel(dockWidgetContents_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_12->addWidget(label_4);

        smoothing = new QDoubleSpinBox(dockWidgetContents_3);
        smoothing->setObjectName(QString::fromUtf8("smoothing"));
        sizePolicy7.setHeightForWidth(smoothing->sizePolicy().hasHeightForWidth());
        smoothing->setSizePolicy(sizePolicy7);
        smoothing->setMaximum(1);
        smoothing->setSingleStep(0.1);

        horizontalLayout_12->addWidget(smoothing);


        gridLayout->addLayout(horizontalLayout_12, 10, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        length_constraint_layout = new QHBoxLayout();
        length_constraint_layout->setSpacing(0);
        length_constraint_layout->setObjectName(QString::fromUtf8("length_constraint_layout"));
        length_constraint_layout->setContentsMargins(-1, 0, -1, -1);
        label_7 = new QLabel(dockWidgetContents_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        length_constraint_layout->addWidget(label_7);

        min_length = new QDoubleSpinBox(dockWidgetContents_3);
        min_length->setObjectName(QString::fromUtf8("min_length"));
        sizePolicy7.setHeightForWidth(min_length->sizePolicy().hasHeightForWidth());
        min_length->setSizePolicy(sizePolicy7);
        min_length->setMaximum(1000);
        min_length->setSingleStep(5);
        min_length->setValue(0);

        length_constraint_layout->addWidget(min_length);

        max_length = new QDoubleSpinBox(dockWidgetContents_3);
        max_length->setObjectName(QString::fromUtf8("max_length"));
        sizePolicy7.setHeightForWidth(max_length->sizePolicy().hasHeightForWidth());
        max_length->setSizePolicy(sizePolicy7);
        max_length->setMinimum(1);
        max_length->setMaximum(10000);
        max_length->setSingleStep(10);
        max_length->setValue(500);

        length_constraint_layout->addWidget(max_length);


        verticalLayout_2->addLayout(length_constraint_layout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        initial_direction = new QComboBox(dockWidgetContents_3);
        initial_direction->setObjectName(QString::fromUtf8("initial_direction"));
        sizePolicy7.setHeightForWidth(initial_direction->sizePolicy().hasHeightForWidth());
        initial_direction->setSizePolicy(sizePolicy7);

        horizontalLayout_3->addWidget(initial_direction);

        seed_plan = new QComboBox(dockWidgetContents_3);
        seed_plan->setObjectName(QString::fromUtf8("seed_plan"));
        sizePolicy7.setHeightForWidth(seed_plan->sizePolicy().hasHeightForWidth());
        seed_plan->setSizePolicy(sizePolicy7);

        horizontalLayout_3->addWidget(seed_plan);

        interpolation = new QComboBox(dockWidgetContents_3);
        interpolation->setObjectName(QString::fromUtf8("interpolation"));
        sizePolicy7.setHeightForWidth(interpolation->sizePolicy().hasHeightForWidth());
        interpolation->setSizePolicy(sizePolicy7);

        horizontalLayout_3->addWidget(interpolation);

        tracking_method = new QComboBox(dockWidgetContents_3);
        tracking_method->setObjectName(QString::fromUtf8("tracking_method"));
        sizePolicy7.setHeightForWidth(tracking_method->sizePolicy().hasHeightForWidth());
        tracking_method->setSizePolicy(sizePolicy7);

        horizontalLayout_3->addWidget(tracking_method);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        track_count = new QSpinBox(dockWidgetContents_3);
        track_count->setObjectName(QString::fromUtf8("track_count"));
        sizePolicy7.setHeightForWidth(track_count->sizePolicy().hasHeightForWidth());
        track_count->setSizePolicy(sizePolicy7);
        track_count->setMinimum(1);
        track_count->setMaximum(1000000000);
        track_count->setSingleStep(2000);
        track_count->setValue(2000);

        horizontalLayout_5->addWidget(track_count);

        tracking_plan = new QComboBox(dockWidgetContents_3);
        tracking_plan->setObjectName(QString::fromUtf8("tracking_plan"));
        sizePolicy7.setHeightForWidth(tracking_plan->sizePolicy().hasHeightForWidth());
        tracking_plan->setSizePolicy(sizePolicy7);
        tracking_plan->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(tracking_plan);

        thread_count = new QComboBox(dockWidgetContents_3);
        thread_count->setObjectName(QString::fromUtf8("thread_count"));
        sizePolicy7.setHeightForWidth(thread_count->sizePolicy().hasHeightForWidth());
        thread_count->setSizePolicy(sizePolicy7);

        horizontalLayout_5->addWidget(thread_count);

        perform_tracking = new QPushButton(dockWidgetContents_3);
        perform_tracking->setObjectName(QString::fromUtf8("perform_tracking"));
        sizePolicy7.setHeightForWidth(perform_tracking->sizePolicy().hasHeightForWidth());
        perform_tracking->setSizePolicy(sizePolicy7);
        perform_tracking->setMaximumSize(QSize(16777215, 25));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/icons/icons/run.xpm"), QSize(), QIcon::Normal, QIcon::Off);
        perform_tracking->setIcon(icon14);

        horizontalLayout_5->addWidget(perform_tracking);

        stopTracking = new QToolButton(dockWidgetContents_3);
        stopTracking->setObjectName(QString::fromUtf8("stopTracking"));
        stopTracking->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(stopTracking);


        verticalLayout_2->addLayout(horizontalLayout_5);

        dockWidget_3->setWidget(dockWidgetContents_3);
        tracking_window->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_3);
        dockWidget_report = new QDockWidget(tracking_window);
        dockWidget_report->setObjectName(QString::fromUtf8("dockWidget_report"));
        sizePolicy.setHeightForWidth(dockWidget_report->sizePolicy().hasHeightForWidth());
        dockWidget_report->setSizePolicy(sizePolicy);
        dockWidget_report->setMinimumSize(QSize(492, 90));
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QString::fromUtf8("dockWidgetContents_6"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents_6);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        report_index = new QComboBox(dockWidgetContents_6);
        report_index->setObjectName(QString::fromUtf8("report_index"));
        report_index->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_14->addWidget(report_index);

        profile_dir = new QComboBox(dockWidgetContents_6);
        profile_dir->setObjectName(QString::fromUtf8("profile_dir"));
        profile_dir->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_14->addWidget(profile_dir);

        label = new QLabel(dockWidgetContents_6);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_14->addWidget(label);

        report_bandwidth = new QDoubleSpinBox(dockWidgetContents_6);
        report_bandwidth->setObjectName(QString::fromUtf8("report_bandwidth"));
        report_bandwidth->setDecimals(1);
        report_bandwidth->setMinimum(0.1);
        report_bandwidth->setMaximum(10);
        report_bandwidth->setSingleStep(0.5);
        report_bandwidth->setValue(1);

        horizontalLayout_14->addWidget(report_bandwidth);

        refresh_report = new QPushButton(dockWidgetContents_6);
        refresh_report->setObjectName(QString::fromUtf8("refresh_report"));
        sizePolicy1.setHeightForWidth(refresh_report->sizePolicy().hasHeightForWidth());
        refresh_report->setSizePolicy(sizePolicy1);
        refresh_report->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_14->addWidget(refresh_report);

        save_report = new QToolButton(dockWidgetContents_6);
        save_report->setObjectName(QString::fromUtf8("save_report"));
        save_report->setMaximumSize(QSize(23, 22));
        save_report->setIcon(icon2);

        horizontalLayout_14->addWidget(save_report);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        label_12 = new QLabel(dockWidgetContents_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_18->addWidget(label_12);

        linewidth = new QSpinBox(dockWidgetContents_6);
        linewidth->setObjectName(QString::fromUtf8("linewidth"));
        linewidth->setMinimum(1);
        linewidth->setMaximum(10);

        horizontalLayout_18->addWidget(linewidth);

        report_legend = new QCheckBox(dockWidgetContents_6);
        report_legend->setObjectName(QString::fromUtf8("report_legend"));
        sizePolicy1.setHeightForWidth(report_legend->sizePolicy().hasHeightForWidth());
        report_legend->setSizePolicy(sizePolicy1);
        report_legend->setMaximumSize(QSize(16777215, 22));

        horizontalLayout_18->addWidget(report_legend);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_18);

        report_widget = new QCustomPlot(dockWidgetContents_6);
        report_widget->setObjectName(QString::fromUtf8("report_widget"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(report_widget->sizePolicy().hasHeightForWidth());
        report_widget->setSizePolicy(sizePolicy9);

        verticalLayout_4->addWidget(report_widget);

        dockWidget_report->setWidget(dockWidgetContents_6);
        tracking_window->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_report);
        color_bar = new QDockWidget(tracking_window);
        color_bar->setObjectName(QString::fromUtf8("color_bar"));
        color_bar->setMinimumSize(QSize(266, 300));
        color_bar->setMaximumSize(QSize(65535, 65535));
        color_bar->setFloating(false);
        color_bar->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents_7 = new QWidget();
        dockWidgetContents_7->setObjectName(QString::fromUtf8("dockWidgetContents_7"));
        verticalLayout_7 = new QVBoxLayout(dockWidgetContents_7);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        splitter_2 = new QSplitter(dockWidgetContents_7);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(9, -1, 9, -1);
        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setMaximumSize(QSize(16777215, 22));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_13);

        tract_color_index = new QComboBox(widget);
        tract_color_index->setObjectName(QString::fromUtf8("tract_color_index"));
        tract_color_index->setMaximumSize(QSize(16777215, 22));

        formLayout->setWidget(0, QFormLayout::FieldRole, tract_color_index);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setMaximumSize(QSize(16777215, 22));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_10);

        color_bar_style = new QComboBox(widget);
        color_bar_style->setObjectName(QString::fromUtf8("color_bar_style"));
        color_bar_style->setMaximumSize(QSize(16777215, 22));

        formLayout->setWidget(1, QFormLayout::FieldRole, color_bar_style);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMaximumSize(QSize(16777215, 22));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_9);

        tract_color_max_value = new QDoubleSpinBox(widget);
        tract_color_max_value->setObjectName(QString::fromUtf8("tract_color_max_value"));
        tract_color_max_value->setMaximumSize(QSize(16777215, 22));
        tract_color_max_value->setDecimals(4);

        formLayout->setWidget(2, QFormLayout::FieldRole, tract_color_max_value);

        label_15 = new QLabel(widget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setMaximumSize(QSize(16777215, 22));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_15);

        tract_color_min_value = new QDoubleSpinBox(widget);
        tract_color_min_value->setObjectName(QString::fromUtf8("tract_color_min_value"));
        tract_color_min_value->setMaximumSize(QSize(16777215, 22));
        tract_color_min_value->setDecimals(4);

        formLayout->setWidget(3, QFormLayout::FieldRole, tract_color_min_value);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(22, 16777215));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_11);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        color_from = new QColorToolButton(widget);
        color_from->setObjectName(QString::fromUtf8("color_from"));
        sizePolicy7.setHeightForWidth(color_from->sizePolicy().hasHeightForWidth());
        color_from->setSizePolicy(sizePolicy7);
        color_from->setMaximumSize(QSize(16777215, 22));
        color_from->setIcon(icon5);

        horizontalLayout_17->addWidget(color_from);

        color_to = new QColorToolButton(widget);
        color_to->setObjectName(QString::fromUtf8("color_to"));
        sizePolicy7.setHeightForWidth(color_to->sizePolicy().hasHeightForWidth());
        color_to->setSizePolicy(sizePolicy7);
        color_to->setMaximumSize(QSize(16777215, 22));
        color_to->setIcon(icon5);

        horizontalLayout_17->addWidget(color_to);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_17);

        update_rendering = new QPushButton(widget);
        update_rendering->setObjectName(QString::fromUtf8("update_rendering"));
        update_rendering->setMaximumSize(QSize(16777215, 22));

        formLayout->setWidget(5, QFormLayout::FieldRole, update_rendering);

        splitter_2->addWidget(widget);
        label_13->raise();
        label_13->raise();
        tract_color_index->raise();
        label_10->raise();
        color_bar_style->raise();
        label_9->raise();
        tract_color_max_value->raise();
        label_15->raise();
        tract_color_min_value->raise();
        label_11->raise();
        update_rendering->raise();
        color_bar_view = new QGraphicsView(splitter_2);
        color_bar_view->setObjectName(QString::fromUtf8("color_bar_view"));
        splitter_2->addWidget(color_bar_view);

        verticalLayout_7->addWidget(splitter_2);

        color_bar->setWidget(dockWidgetContents_7);
        tracking_window->addDockWidget(static_cast<Qt::DockWidgetArea>(2), color_bar);
        vbc_widget = new QDockWidget(tracking_window);
        vbc_widget->setObjectName(QString::fromUtf8("vbc_widget"));
        dockWidgetContents_8 = new QWidget();
        dockWidgetContents_8->setObjectName(QString::fromUtf8("dockWidgetContents_8"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents_8);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        tabWidget = new QTabWidget(dockWidgetContents_8);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_8 = new QVBoxLayout(tab_5);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(0);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        vbc_open_subject = new QToolButton(tab_5);
        vbc_open_subject->setObjectName(QString::fromUtf8("vbc_open_subject"));
        vbc_open_subject->setMaximumSize(QSize(23, 22));
        vbc_open_subject->setIcon(icon1);

        horizontalLayout_20->addWidget(vbc_open_subject);

        label_14 = new QLabel(tab_5);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_20->addWidget(label_14);

        doubleSpinBox = new QDoubleSpinBox(tab_5);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMaximum(0.5);
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox->setValue(0.02);

        horizontalLayout_20->addWidget(doubleSpinBox);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_20->addItem(horizontalSpacer_7);


        verticalLayout_8->addLayout(horizontalLayout_20);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);

        tabWidget->addTab(tab_5, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_21 = new QHBoxLayout(tab_3);
        horizontalLayout_21->setSpacing(0);
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        vbc_report = new QCustomPlot(tab_3);
        vbc_report->setObjectName(QString::fromUtf8("vbc_report"));

        horizontalLayout_21->addWidget(vbc_report);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_6 = new QVBoxLayout(tab_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        splitter = new QSplitter(tab_4);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        vbc_view = new QGraphicsView(splitter);
        vbc_view->setObjectName(QString::fromUtf8("vbc_view"));
        splitter->addWidget(vbc_view);
        subject_list = new QTableWidget(splitter);
        if (subject_list->columnCount() < 3)
            subject_list->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        subject_list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        subject_list->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        subject_list->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        subject_list->setObjectName(QString::fromUtf8("subject_list"));
        QSizePolicy sizePolicy10(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(subject_list->sizePolicy().hasHeightForWidth());
        subject_list->setSizePolicy(sizePolicy10);
        subject_list->setSelectionMode(QAbstractItemView::SingleSelection);
        subject_list->setSelectionBehavior(QAbstractItemView::SelectRows);
        splitter->addWidget(subject_list);

        verticalLayout_6->addWidget(splitter);

        tabWidget->addTab(tab_4, QString());

        verticalLayout_5->addWidget(tabWidget);

        vbc_widget->setWidget(dockWidgetContents_8);
        tracking_window->addDockWidget(static_cast<Qt::DockWidgetArea>(2), vbc_widget);

        menuBar->addAction(menu_Edit->menuAction());
        menuBar->addAction(menuRegions->menuAction());
        menuBar->addAction(menuTracts->menuAction());
        menuBar->addAction(menu_Slices->menuAction());
        menuBar->addAction(menu_View->menuAction());
        menuBar->addAction(menuConnectometry->menuAction());
        menuRegions->addAction(actionNewRegion);
        menuRegions->addAction(actionOpenRegion);
        menuRegions->addAction(actionSaveRegionAs);
        menuRegions->addAction(actionSave_Voxel_Data_As);
        menuRegions->addAction(actionDeleteRegion);
        menuRegions->addAction(actionDeleteRegionAll);
        menuRegions->addSeparator();
        menuRegions->addAction(menuModify->menuAction());
        menuRegions->addAction(actionWhole_brain_seeding);
        menuModify->addAction(actionShift_X);
        menuModify->addAction(actionShift_X_2);
        menuModify->addAction(actionShift_Y);
        menuModify->addAction(actionShift_Y_2);
        menuModify->addAction(actionShift_Z);
        menuModify->addAction(actionShift_Z_2);
        menuModify->addSeparator();
        menuModify->addAction(actionFlip_X);
        menuModify->addAction(actionFlip_Y);
        menuModify->addAction(actionFlip_Z);
        menuModify->addSeparator();
        menuModify->addAction(actionDilation);
        menuModify->addAction(actionErosion);
        menuModify->addAction(actionSmoothing);
        menuModify->addAction(actionNegate);
        menuModify->addAction(actionDefragment);
        menuModify->addAction(actionThreshold);
        menuTracts->addAction(actionOpenTract);
        menuTracts->addAction(actionSaveTractAs);
        menuTracts->addAction(actionSave_All_Tracts_As);
        menuTracts->addAction(menuSave->menuAction());
        menuTracts->addAction(menuExport_Tract_Density->menuAction());
        menuTracts->addSeparator();
        menuTracts->addAction(actionMerge_All);
        menuTracts->addAction(actionDeleteTract);
        menuTracts->addAction(actionDeleteTractAll);
        menuTracts->addSeparator();
        menuTracts->addAction(actionEndpoints_to_seeding);
        menuTracts->addAction(actionTracts_to_seeds);
        menuTracts->addSeparator();
        menuTracts->addAction(actionSet_Color);
        menuTracts->addAction(actionOpen_Colors);
        menuTracts->addSeparator();
        menuTracts->addAction(actionOpen_Cluster_Labels);
        menuTracts->addAction(menuClustering->menuAction());
        menuTracts->addSeparator();
        menuTracts->addAction(actionSave_Tracts_Colors_As);
        menuTracts->addAction(actionSave_Tracts_in_Current_Mapping);
        menuTracts->addAction(actionSave_Tracts_in_MNI_space);
        menuTracts->addAction(actionSave_Endpoints_in_Current_Mapping);
        menuTracts->addAction(actionStatistics);
        menuSave->addAction(actionQuantitative_anisotropy_QA);
        menuClustering->addAction(actionK_means);
        menuClustering->addAction(actionEM);
        menuClustering->addAction(actionHierarchical);
        menuExport_Tract_Density->addAction(actionTDI_Diffusion_Space);
        menuExport_Tract_Density->addAction(actionTDI_Subvoxel_Diffusion_Space);
        menuExport_Tract_Density->addAction(actionTDI_Import_Slice_Space);
        menu_Edit->addAction(actionUndo);
        menu_Edit->addAction(actionRedo);
        menu_Edit->addSeparator();
        menu_Edit->addAction(actionSelect_Tracts);
        menu_Edit->addAction(actionDelete);
        menu_Edit->addAction(actionTrim);
        menu_Edit->addAction(actionCut);
        menu_Edit->addAction(actionPaint);
        menu_Edit->addSeparator();
        menu_Edit->addAction(actionMove_Object);
        menu_View->addAction(actionZoom_In);
        menu_View->addAction(actionZoom_Out);
        menu_View->addSeparator();
        menu_View->addAction(actionSagittal_view);
        menu_View->addAction(actionCoronal_View);
        menu_View->addAction(actionAxial_View);
        menu_View->addSeparator();
        menu_View->addAction(actionLoad_Camera);
        menu_View->addAction(actionSave_Camera);
        menu_View->addSeparator();
        menu_View->addAction(actionSave_Screen);
        menu_View->addAction(actionSave_ROI_Screen);
        menu_View->addAction(actionSave_Anisotrpy_Map_as);
        menu_View->addAction(actionSave_Report_as);
        menu_View->addAction(actionSave_Rotation_Images);
        menu_View->addAction(actionSave_Left_Right_3D_Image);
        menu_View->addAction(actionCopy_to_clipboard);
        menu_View->addSeparator();
        menu_View->addAction(actionRestore_window_layout);
        menu_Slices->addAction(actionInsert_T1_T2);
        menu_Slices->addAction(actionAdd_surface);
        menu_Slices->addSeparator();
        menu_Slices->addAction(actionSave_mapping);
        menu_Slices->addAction(actionLoad_mapping);
        menu_Slices->addSeparator();
        menuConnectometry->addAction(actionOpen_Subject_Data);

        retranslateUi(tracking_window);
        QObject::connect(tbNewRegion, SIGNAL(clicked()), actionNewRegion, SLOT(trigger()));
        QObject::connect(tbOpenRegion, SIGNAL(clicked()), actionOpenRegion, SLOT(trigger()));
        QObject::connect(tbSaveRegion, SIGNAL(clicked()), actionSaveRegionAs, SLOT(trigger()));
        QObject::connect(tbDeleteRegion, SIGNAL(clicked()), actionDeleteRegion, SLOT(trigger()));
        QObject::connect(glAxiBox, SIGNAL(valueChanged(int)), glAxiSlider, SLOT(setValue(int)));
        QObject::connect(glCorBox, SIGNAL(valueChanged(int)), glCorSlider, SLOT(setValue(int)));
        QObject::connect(glSagBox, SIGNAL(valueChanged(int)), glSagSlider, SLOT(setValue(int)));
        QObject::connect(glAxiSlider, SIGNAL(valueChanged(int)), glAxiBox, SLOT(setValue(int)));
        QObject::connect(glCorSlider, SIGNAL(valueChanged(int)), glCorBox, SLOT(setValue(int)));
        QObject::connect(glSagSlider, SIGNAL(valueChanged(int)), glSagBox, SLOT(setValue(int)));
        QObject::connect(isosurfaceButton, SIGNAL(clicked()), actionAdd_surface, SLOT(trigger()));
        QObject::connect(tbSaveTract, SIGNAL(clicked()), actionSave_All_Tracts_As, SLOT(trigger()));
        QObject::connect(tbOpenTract, SIGNAL(clicked()), actionOpenTract, SLOT(trigger()));
        QObject::connect(tbDeleteTract, SIGNAL(clicked()), actionDeleteTract, SLOT(trigger()));

        initial_direction->setCurrentIndex(0);
        tracking_plan->setCurrentIndex(1);
        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(tracking_window);
    } // setupUi

    void retranslateUi(QMainWindow *tracking_window)
    {
        tracking_window->setWindowTitle(QApplication::translate("tracking_window", "Fiber Tracking", 0, QApplication::UnicodeUTF8));
        actionNewRegion->setText(QApplication::translate("tracking_window", "&New", 0, QApplication::UnicodeUTF8));
        actionOpenRegion->setText(QApplication::translate("tracking_window", "&Open...", 0, QApplication::UnicodeUTF8));
        actionSaveRegionAs->setText(QApplication::translate("tracking_window", "Save &As...", 0, QApplication::UnicodeUTF8));
        actionDeleteRegion->setText(QApplication::translate("tracking_window", "&Delete", 0, QApplication::UnicodeUTF8));
        actionOpenTract->setText(QApplication::translate("tracking_window", "Open Tracts...", 0, QApplication::UnicodeUTF8));
        actionSaveTractAs->setText(QApplication::translate("tracking_window", "Save Tracts As...", 0, QApplication::UnicodeUTF8));
        actionSaveTractFA->setText(QApplication::translate("tracking_window", "Save tract anisotropy as...", 0, QApplication::UnicodeUTF8));
        actionDeleteRegionAll->setText(QApplication::translate("tracking_window", "Delete All", 0, QApplication::UnicodeUTF8));
        actionDeleteTract->setText(QApplication::translate("tracking_window", "Delete", 0, QApplication::UnicodeUTF8));
        actionDeleteTractAll->setText(QApplication::translate("tracking_window", "Delete All", 0, QApplication::UnicodeUTF8));
        actionShift_X->setText(QApplication::translate("tracking_window", "Shift +X", 0, QApplication::UnicodeUTF8));
        actionShift_X->setShortcut(QApplication::translate("tracking_window", "Ctrl+1", 0, QApplication::UnicodeUTF8));
        actionShift_X_2->setText(QApplication::translate("tracking_window", "Shift -X", 0, QApplication::UnicodeUTF8));
        actionShift_X_2->setShortcut(QApplication::translate("tracking_window", "Ctrl+2", 0, QApplication::UnicodeUTF8));
        actionShift_Y->setText(QApplication::translate("tracking_window", "Shift +Y", 0, QApplication::UnicodeUTF8));
        actionShift_Y->setShortcut(QApplication::translate("tracking_window", "Ctrl+3", 0, QApplication::UnicodeUTF8));
        actionShift_Y_2->setText(QApplication::translate("tracking_window", "Shift -Y", 0, QApplication::UnicodeUTF8));
        actionShift_Y_2->setShortcut(QApplication::translate("tracking_window", "Ctrl+4", 0, QApplication::UnicodeUTF8));
        actionShift_Z->setText(QApplication::translate("tracking_window", "Shift +Z", 0, QApplication::UnicodeUTF8));
        actionShift_Z->setShortcut(QApplication::translate("tracking_window", "Ctrl+5", 0, QApplication::UnicodeUTF8));
        actionShift_Z_2->setText(QApplication::translate("tracking_window", "Shift -Z", 0, QApplication::UnicodeUTF8));
        actionShift_Z_2->setShortcut(QApplication::translate("tracking_window", "Ctrl+6", 0, QApplication::UnicodeUTF8));
        actionFlip_X->setText(QApplication::translate("tracking_window", "Flip X", 0, QApplication::UnicodeUTF8));
        actionFlip_X->setShortcut(QApplication::translate("tracking_window", "Ctrl+7", 0, QApplication::UnicodeUTF8));
        actionFlip_Y->setText(QApplication::translate("tracking_window", "Flip Y", 0, QApplication::UnicodeUTF8));
        actionFlip_Y->setShortcut(QApplication::translate("tracking_window", "Ctrl+8", 0, QApplication::UnicodeUTF8));
        actionFlip_Z->setText(QApplication::translate("tracking_window", "Flip Z", 0, QApplication::UnicodeUTF8));
        actionFlip_Z->setShortcut(QApplication::translate("tracking_window", "Ctrl+9", 0, QApplication::UnicodeUTF8));
        actionDilation->setText(QApplication::translate("tracking_window", "Dilation", 0, QApplication::UnicodeUTF8));
        actionDilation->setShortcut(QApplication::translate("tracking_window", "Ctrl+Shift+D", 0, QApplication::UnicodeUTF8));
        actionErosion->setText(QApplication::translate("tracking_window", "Erosion", 0, QApplication::UnicodeUTF8));
        actionErosion->setShortcut(QApplication::translate("tracking_window", "Ctrl+Shift+E", 0, QApplication::UnicodeUTF8));
        actionSmoothing->setText(QApplication::translate("tracking_window", "Smoothing", 0, QApplication::UnicodeUTF8));
        actionSmoothing->setShortcut(QApplication::translate("tracking_window", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionNegate->setText(QApplication::translate("tracking_window", "Negate", 0, QApplication::UnicodeUTF8));
        actionNegate->setShortcut(QApplication::translate("tracking_window", "Ctrl+Shift+N", 0, QApplication::UnicodeUTF8));
        actionDefragment->setText(QApplication::translate("tracking_window", "Defragment", 0, QApplication::UnicodeUTF8));
        actionDefragment->setShortcut(QApplication::translate("tracking_window", "Ctrl+Shift+F", 0, QApplication::UnicodeUTF8));
        actionWhole_brain_seeding->setText(QApplication::translate("tracking_window", "Whole Brain Seeding", 0, QApplication::UnicodeUTF8));
        actionSelect_Tracts->setText(QApplication::translate("tracking_window", "Select", 0, QApplication::UnicodeUTF8));
        actionSelect_Tracts->setShortcut(QApplication::translate("tracking_window", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionUndo->setText(QApplication::translate("tracking_window", "Undo", 0, QApplication::UnicodeUTF8));
        actionUndo->setShortcut(QApplication::translate("tracking_window", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionDelete->setText(QApplication::translate("tracking_window", "Delete", 0, QApplication::UnicodeUTF8));
        actionDelete->setShortcut(QApplication::translate("tracking_window", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionTrim->setText(QApplication::translate("tracking_window", "Trim", 0, QApplication::UnicodeUTF8));
        actionTrim->setShortcut(QApplication::translate("tracking_window", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("tracking_window", "Cut", 0, QApplication::UnicodeUTF8));
        actionCut->setShortcut(QApplication::translate("tracking_window", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setText(QApplication::translate("tracking_window", "Zoom &In", 0, QApplication::UnicodeUTF8));
        actionZoom_In->setShortcut(QApplication::translate("tracking_window", "F3", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setText(QApplication::translate("tracking_window", "Zoom Out&", 0, QApplication::UnicodeUTF8));
        actionZoom_Out->setShortcut(QApplication::translate("tracking_window", "F4", 0, QApplication::UnicodeUTF8));
        actionSagittal_view->setText(QApplication::translate("tracking_window", "&Sagittal View", 0, QApplication::UnicodeUTF8));
        actionSagittal_view->setShortcut(QApplication::translate("tracking_window", "F5", 0, QApplication::UnicodeUTF8));
        actionCoronal_View->setText(QApplication::translate("tracking_window", "&Coronal View", 0, QApplication::UnicodeUTF8));
        actionCoronal_View->setShortcut(QApplication::translate("tracking_window", "F6", 0, QApplication::UnicodeUTF8));
        actionAxial_View->setText(QApplication::translate("tracking_window", "&Axial View", 0, QApplication::UnicodeUTF8));
        actionAxial_View->setShortcut(QApplication::translate("tracking_window", "F7", 0, QApplication::UnicodeUTF8));
        actionQuantitative_anisotropy_QA->setText(QApplication::translate("tracking_window", "Save Quantitative anisotropy (QA)", 0, QApplication::UnicodeUTF8));
        actionMerge_All->setText(QApplication::translate("tracking_window", "Merge All", 0, QApplication::UnicodeUTF8));
        actionSave_Screen->setText(QApplication::translate("tracking_window", "Save 3D Screen...", 0, QApplication::UnicodeUTF8));
        actionSave_ROI_Screen->setText(QApplication::translate("tracking_window", "Save ROI Screen...", 0, QApplication::UnicodeUTF8));
        actionLoad_Camera->setText(QApplication::translate("tracking_window", "Open Camera...", 0, QApplication::UnicodeUTF8));
        actionSave_Camera->setText(QApplication::translate("tracking_window", "Save Camera", 0, QApplication::UnicodeUTF8));
        actionEndpoints_to_seeding->setText(QApplication::translate("tracking_window", "Endpoints To ROI", 0, QApplication::UnicodeUTF8));
        actionTracts_to_seeds->setText(QApplication::translate("tracking_window", "Tracts To ROI", 0, QApplication::UnicodeUTF8));
        actionSave_Rotation_Images->setText(QApplication::translate("tracking_window", "Save Rotation Images...", 0, QApplication::UnicodeUTF8));
        actionPaint->setText(QApplication::translate("tracking_window", "Paint", 0, QApplication::UnicodeUTF8));
        actionPaint->setShortcut(QApplication::translate("tracking_window", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionInsert_T1_T2->setText(QApplication::translate("tracking_window", "Insert T1/T2...", 0, QApplication::UnicodeUTF8));
        actionAdd_surface->setText(QApplication::translate("tracking_window", "Add Isosurface", 0, QApplication::UnicodeUTF8));
        actionSave_mapping->setText(QApplication::translate("tracking_window", "Save Mapping...", 0, QApplication::UnicodeUTF8));
        actionLoad_mapping->setText(QApplication::translate("tracking_window", "Load Mapping...", 0, QApplication::UnicodeUTF8));
        actionStatistics->setText(QApplication::translate("tracking_window", "&Statistics...", 0, QApplication::UnicodeUTF8));
        actionK_means->setText(QApplication::translate("tracking_window", "K-means", 0, QApplication::UnicodeUTF8));
        actionEM->setText(QApplication::translate("tracking_window", "EM", 0, QApplication::UnicodeUTF8));
        actionHierarchical->setText(QApplication::translate("tracking_window", "Hierarchical", 0, QApplication::UnicodeUTF8));
        actionSet_Color->setText(QApplication::translate("tracking_window", "Set Color...", 0, QApplication::UnicodeUTF8));
        actionSave_Tracts_Colors_As->setText(QApplication::translate("tracking_window", "Save Tracts Colors As...", 0, QApplication::UnicodeUTF8));
        actionOpen_Colors->setText(QApplication::translate("tracking_window", "Open Colors...", 0, QApplication::UnicodeUTF8));
        actionSave_Voxel_Data_As->setText(QApplication::translate("tracking_window", "Save &Region Data As...", 0, QApplication::UnicodeUTF8));
        actionTDI_Diffusion_Space->setText(QApplication::translate("tracking_window", "Diffusion Space...", 0, QApplication::UnicodeUTF8));
        actionTDI_Import_Slice_Space->setText(QApplication::translate("tracking_window", "Current Slice Space...", 0, QApplication::UnicodeUTF8));
        actionTDI_Subvoxel_Diffusion_Space->setText(QApplication::translate("tracking_window", "Subvoxel Diffusion Space...", 0, QApplication::UnicodeUTF8));
        actionSave_Tracts_in_Current_Mapping->setText(QApplication::translate("tracking_window", "Save Tracts In T1/T2 Space...", 0, QApplication::UnicodeUTF8));
        actionThreshold->setText(QApplication::translate("tracking_window", "Threshold", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("tracking_window", "Redo", 0, QApplication::UnicodeUTF8));
        actionRedo->setShortcut(QApplication::translate("tracking_window", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionCopy_to_clipboard->setText(QApplication::translate("tracking_window", "Copy to clipboard", 0, QApplication::UnicodeUTF8));
        actionCopy_to_clipboard->setShortcut(QApplication::translate("tracking_window", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionSave_Anisotrpy_Map_as->setText(QApplication::translate("tracking_window", "Save anisotrpy map As...", 0, QApplication::UnicodeUTF8));
        actionRestore_window_layout->setText(QApplication::translate("tracking_window", "Restore window layout", 0, QApplication::UnicodeUTF8));
        actionSave_Endpoints_in_Current_Mapping->setText(QApplication::translate("tracking_window", "Save Endpoints InT1/T2 space...", 0, QApplication::UnicodeUTF8));
        actionMove_Object->setText(QApplication::translate("tracking_window", "Move Onject", 0, QApplication::UnicodeUTF8));
        actionMove_Object->setShortcut(QApplication::translate("tracking_window", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionSave_Report_as->setText(QApplication::translate("tracking_window", "Save Report As...", 0, QApplication::UnicodeUTF8));
        actionSave_Tracts_in_MNI_space->setText(QApplication::translate("tracking_window", "Save Tracts In MNI Space...", 0, QApplication::UnicodeUTF8));
        actionOpen_Clusters->setText(QApplication::translate("tracking_window", "Open Clusters...", 0, QApplication::UnicodeUTF8));
        actionSave_Clusters->setText(QApplication::translate("tracking_window", "Save Clusters...", 0, QApplication::UnicodeUTF8));
        actionOpen_Cluster_Labels->setText(QApplication::translate("tracking_window", "Open Cluster Labels...", 0, QApplication::UnicodeUTF8));
        actionSave_All_Tracts_As->setText(QApplication::translate("tracking_window", "Save All Tracts As...", 0, QApplication::UnicodeUTF8));
        actionSave_Left_Right_3D_Image->setText(QApplication::translate("tracking_window", "Save Left/Right 3D Image...", 0, QApplication::UnicodeUTF8));
        actionOpen_Subject_Data->setText(QApplication::translate("tracking_window", "Open Subject Data...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("tracking_window", "Current Slice:", 0, QApplication::UnicodeUTF8));
        SliceModality->clear();
        SliceModality->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Diffusion", 0, QApplication::UnicodeUTF8)
        );
        addSlices->setText(QString());
        deleteSlice->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        isosurfaceButton->setText(QApplication::translate("tracking_window", "+isosurface", 0, QApplication::UnicodeUTF8));
        surfaceStyle->clear();
        surfaceStyle->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Full", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Right Hemisphere", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Left Hemisphere", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Lower Brain", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Upper Brain", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Anterior Half", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Posterior Half", 0, QApplication::UnicodeUTF8)
        );
        glSagCheck->setText(QString());
        glSagView->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        glCorCheck->setText(QString());
        glCorView->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        glAxiCheck->setText(QString());
        glAxiView->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        regionDockWidget->setWindowTitle(QApplication::translate("tracking_window", "Region List", 0, QApplication::UnicodeUTF8));
        tbNewRegion->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        tbOpenRegion->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        tbSaveRegion->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        tbDeleteRegion->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        whole_brain->setToolTip(QApplication::translate("tracking_window", "Whole brain seeding", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        whole_brain->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        addRegionFromAtlas->setText(QApplication::translate("tracking_window", "Add", 0, QApplication::UnicodeUTF8));
        renderingWidgetHolder->setWindowTitle(QApplication::translate("tracking_window", "Rendering Options", 0, QApplication::UnicodeUTF8));
        tbDefaultParam->setText(QApplication::translate("tracking_window", "Set All To Default", 0, QApplication::UnicodeUTF8));
        RenderingQualityBox->clear();
        RenderingQualityBox->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Best Performance", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Default", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Highest Quality", 0, QApplication::UnicodeUTF8)
        );
        menuRegions->setTitle(QApplication::translate("tracking_window", "&Regions", 0, QApplication::UnicodeUTF8));
        menuModify->setTitle(QApplication::translate("tracking_window", "Modify Current Region", 0, QApplication::UnicodeUTF8));
        menuTracts->setTitle(QApplication::translate("tracking_window", "Tr&acts", 0, QApplication::UnicodeUTF8));
        menuSave->setTitle(QApplication::translate("tracking_window", "Save Index", 0, QApplication::UnicodeUTF8));
        menuClustering->setTitle(QApplication::translate("tracking_window", "Clustering", 0, QApplication::UnicodeUTF8));
        menuExport_Tract_Density->setTitle(QApplication::translate("tracking_window", "Export Tract Density", 0, QApplication::UnicodeUTF8));
        menu_Edit->setTitle(QApplication::translate("tracking_window", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_View->setTitle(QApplication::translate("tracking_window", "&View", 0, QApplication::UnicodeUTF8));
        menu_Slices->setTitle(QApplication::translate("tracking_window", "&Slices", 0, QApplication::UnicodeUTF8));
        menuConnectometry->setTitle(QApplication::translate("tracking_window", "Connectometry", 0, QApplication::UnicodeUTF8));
        TractWidgetHolder->setWindowTitle(QApplication::translate("tracking_window", "Fiber Tracts", 0, QApplication::UnicodeUTF8));
        tbOpenTract->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        tbSaveTract->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        tbDeleteTract->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        dockWidget->setWindowTitle(QApplication::translate("tracking_window", "Step1: select regions", 0, QApplication::UnicodeUTF8));
        zoomIn->setText(QApplication::translate("tracking_window", "+", 0, QApplication::UnicodeUTF8));
        zoomOut->setText(QApplication::translate("tracking_window", "-", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tool0->setToolTip(QApplication::translate("tracking_window", "Rectangle seeding", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tool0->setText(QApplication::translate("tracking_window", "Rec", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tool1->setToolTip(QApplication::translate("tracking_window", "Polygon seeding", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tool1->setText(QApplication::translate("tracking_window", "Poly", 0, QApplication::UnicodeUTF8));
        tool4->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tool2->setToolTip(QApplication::translate("tracking_window", "Ball seeding", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tool2->setText(QApplication::translate("tracking_window", "Ball", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tool3->setToolTip(QApplication::translate("tracking_window", "Cubic seeding", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tool3->setText(QApplication::translate("tracking_window", "Cubic", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        tool5->setToolTip(QApplication::translate("tracking_window", "move object", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        tool5->setText(QString());
        view_style->clear();
        view_style->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Single slice", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Mosaic", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Mosaic2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Mosaic4", 0, QApplication::UnicodeUTF8)
        );
        overlay->clear();
        overlay->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "No overlay", 0, QApplication::UnicodeUTF8)
        );
        show_fiber->setText(QApplication::translate("tracking_window", "Fibers", 0, QApplication::UnicodeUTF8));
        show_pos->setText(QApplication::translate("tracking_window", "Pos", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("tracking_window", "Contrast", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("tracking_window", "Offset", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        SagView->setToolTip(QApplication::translate("tracking_window", "Sagittal view", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        SagView->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        CorView->setToolTip(QApplication::translate("tracking_window", "Coronal view", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        CorView->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        AxiView->setToolTip(QApplication::translate("tracking_window", "Axial view", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        AxiView->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        dockWidget_3->setWindowTitle(QApplication::translate("tracking_window", "Step2: setup parameters and perform tracking", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("tracking_window", "Max Angle", 0, QApplication::UnicodeUTF8));
        turning_angle->setSuffix(QString());
        label_5->setText(QApplication::translate("tracking_window", "Step Size (mm)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("tracking_window", "Smoothing", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("tracking_window", "Length constraint (mm)", 0, QApplication::UnicodeUTF8));
        initial_direction->clear();
        initial_direction->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Primary Orientation", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Random Orientation", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "All Orientations", 0, QApplication::UnicodeUTF8)
        );
        seed_plan->clear();
        seed_plan->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Subvoxel", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Voxelwise", 0, QApplication::UnicodeUTF8)
        );
        interpolation->clear();
        interpolation->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Trilinear", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Gaussian radial basis", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Nearest neighbor", 0, QApplication::UnicodeUTF8)
        );
        tracking_method->clear();
        tracking_method->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Streamline", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "RK4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Voxel Tracking", 0, QApplication::UnicodeUTF8)
        );
        tracking_plan->clear();
        tracking_plan->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Seeds", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Tracts", 0, QApplication::UnicodeUTF8)
        );
        thread_count->clear();
        thread_count->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "1 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "2 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "3 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "4 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "5 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "6 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "7 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "8 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "9 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "10 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "11 Threads", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "12 Threads", 0, QApplication::UnicodeUTF8)
        );
        perform_tracking->setText(QApplication::translate("tracking_window", "Tracking", 0, QApplication::UnicodeUTF8));
        stopTracking->setText(QApplication::translate("tracking_window", "Stop", 0, QApplication::UnicodeUTF8));
        dockWidget_report->setWindowTitle(QApplication::translate("tracking_window", "Reports", 0, QApplication::UnicodeUTF8));
        profile_dir->clear();
        profile_dir->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "X direction", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Y direction", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Z direction", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "fiber orientation", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "mean of each fiber", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("tracking_window", "Bandwidth:", 0, QApplication::UnicodeUTF8));
        refresh_report->setText(QApplication::translate("tracking_window", "Update", 0, QApplication::UnicodeUTF8));
        save_report->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("tracking_window", "Line Width", 0, QApplication::UnicodeUTF8));
        report_legend->setText(QApplication::translate("tracking_window", "Legend", 0, QApplication::UnicodeUTF8));
        color_bar->setWindowTitle(QApplication::translate("tracking_window", "Color Bar", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("tracking_window", "Index", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("tracking_window", "Style", 0, QApplication::UnicodeUTF8));
        color_bar_style->clear();
        color_bar_style->insertItems(0, QStringList()
         << QApplication::translate("tracking_window", "Two colors", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("tracking_window", "Color spectrum", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("tracking_window", "Max value", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("tracking_window", "Min value", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("tracking_window", "Color", 0, QApplication::UnicodeUTF8));
        color_from->setText(QString());
        color_to->setText(QString());
        update_rendering->setText(QApplication::translate("tracking_window", "Update", 0, QApplication::UnicodeUTF8));
        vbc_widget->setWindowTitle(QApplication::translate("tracking_window", "Connectometry Analysis", 0, QApplication::UnicodeUTF8));
        vbc_open_subject->setText(QApplication::translate("tracking_window", "...", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("tracking_window", "FDR:", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("tracking_window", "Individual Analysis", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("tracking_window", "Distribution ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = subject_list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("tracking_window", "Subject ID", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = subject_list->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("tracking_window", "Value", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = subject_list->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("tracking_window", "R2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("tracking_window", "Subject Data", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class tracking_window: public Ui_tracking_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKING_WINDOW_H
