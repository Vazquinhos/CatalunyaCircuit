QT += core gui opengl

unix:!macx {
        LIBS += -lglut -lGLEW -lGLU
}
win32 {
        LIBS += "C:\Archivos de programa\Microsoft SDKs\Windows\v6.1\Lib\glew32.lib"
}
macx {
        LIBS += -framework GLUT
}

TARGET = Thoth
TEMPLATE = app


SOURCES += main.cpp\
    Objects/objectmanager.cpp \
    Objects/object3DFile.cpp \
    Objects/enviroment.cpp \
    Objects/car.cpp \
    Objects/absObject3D.cpp \
    Scene/scene.cpp \
    Scene/fragmentview.cpp \
    Utils/vector3D.cpp \
    Utils/point3D.cpp \
    Utils/point2D.cpp \
    Cameras/sphericalcamera.cpp \
    Cameras/freecamera.cpp \
    Cameras/fixedcamera.cpp \
    Cameras/cameramanager.cpp \
    Cameras/cameraabs.cpp \
    Lights/lightmanager.cpp \
    Lights/light.cpp \
    Loaders/settingsexporter.cpp \
    Loaders/lightloader.cpp \
    Loaders/fileParser.cpp \
    Loaders/camerasloader.cpp \
    Ui/lightswindowqt.cpp \
    Ui/importsettingsqt.cpp \
    Ui/exportsettingsqt.cpp \
    Ui/errorwindow.cpp \
    Scene/contextgl.cpp \
    Ui/mainwindow.cpp \
    Ui/camerawindowqt.cpp \
    Ui/carswindowqt.cpp \
    Objects/absModels.cpp \
    Loaders/settingsimporter.cpp \
    Commands/camerascmd.cpp \
    Objects/modelManager.cpp \
    Ui/newcameraqt.cpp

HEADERS  += \
    Objects/objectmanager.h \
    Objects/object3DFile.h \
    Objects/enviroment.h \
    Objects/car.h \
    Objects/absObject3D.h \
    Scene/scene.h \
    Scene/fragmentview.h \
    Utils/vector3D.h \
    Utils/util.h \
    Utils/point3D.h \
    Utils/point2D.h \
    Cameras/sphericalcamera.h \
    Cameras/freecamera.h \
    Cameras/fixedcamera.h \
    Cameras/cameramanager.h \
    Cameras/cameraabs.h \
    Lights/lightmanager.h \
    Lights/light.h \
    Loaders/settingsexporter.h \
    Loaders/lightloader.h \
    Loaders/fileParser.h \
    Loaders/camerasloader.h \
    Ui/lightswindowqt.h \
    Ui/importsettingsqt.h \
    Ui/exportsettingsqt.h \
    Ui/errorwindow.h \
    Scene/contextgl.h \
    Ui/mainwindow.h \
    Ui/camerawindowqt.h \
    Ui/carswindowqt.h \
    Objects/absModels.h \
    Loaders/settingsimporter.h \
    Commands/camerascmd.h \
    Objects/modelManager.h \
    Ui/newcameraqt.h

FORMS    += \
    Ui/lightswindowqt.ui \
    Ui/importsettingsqt.ui \
    Ui/exportsettingsqt.ui \
    Ui/errorwindow.ui \
    Ui/mainwindow.ui \
    Ui/camerawindowqt.ui \
    Ui/carswindowqt.ui \
    Ui/newcameraqt.ui

OTHER_FILES += \
    simple.vert \
    simple.frag \
    Media/Models/wheelRearRight.3ds \
    Media/Models/wheelRearLeft.3ds \
    Media/Models/wheelFrontRight.3ds \
    Media/Models/wheelFrontLeft.3ds \
    Media/Models/Wheel.lwo \
    Media/Models/wheel4.tga \
    Media/Models/wheel3.tga \
    Media/Models/wheel2.tga \
    Media/Models/wheel.3ds \
    Media/Models/vpower_board_a.dds \
    Media/Models/vpowe040.dds \
    Media/Models/vegetacion_25.3ds \
    Media/Models/vegetacion_24.3ds \
    Media/Models/vegetacion_23.3ds \
    Media/Models/vegetacion_22.3ds \
    Media/Models/vegetacion_21.3ds \
    Media/Models/vegetacion_20.3ds \
    Media/Models/vegetacion_19.3ds \
    Media/Models/vegetacion_18.3ds \
    Media/Models/vegetacion_17.3ds \
    Media/Models/vegetacion_16.3ds \
    Media/Models/vegetacion_15.3ds \
    Media/Models/vegetacion_14.3ds \
    Media/Models/vegetacion_13.3ds \
    Media/Models/vegetacion_12.3ds \
    Media/Models/vegetacion_11.3ds \
    Media/Models/vegetacion_10.3ds \
    Media/Models/vegetacion_9.3ds \
    Media/Models/vegetacion_8.3ds \
    Media/Models/vegetacion_7.3ds \
    Media/Models/vegetacion_6.3ds \
    Media/Models/vegetacion_5.3ds \
    Media/Models/vegetacion_4.3ds \
    Media/Models/vegetacion_3.3ds \
    Media/Models/vegetacion_2.3ds \
    Media/Models/vegetacion_1.3ds \
    Media/Models/vallasPlastico_40.3ds \
    Media/Models/vallasPlastico_39.3ds \
    Media/Models/vallasPlastico_38.3ds \
    Media/Models/vallasPlastico_37.3ds \
    Media/Models/vallasPlastico_36.3ds \
    Media/Models/vallasPlastico_35.3ds \
    Media/Models/vallasPlastico_34.3ds \
    Media/Models/vallasPlastico_33.3ds \
    Media/Models/vallasPlastico_32.3ds \
    Media/Models/vallasPlastico_31.3ds \
    Media/Models/vallasPlastico_30.3ds \
    Media/Models/vallasPlastico_29.3ds \
    Media/Models/vallasPlastico_28.3ds \
    Media/Models/vallasPlastico_27.3ds \
    Media/Models/vallasPlastico_26.3ds \
    Media/Models/vallasPlastico_25.3ds \
    Media/Models/vallasPlastico_24.3ds \
    Media/Models/vallasPlastico_23.3ds \
    Media/Models/vallasPlastico_22.3ds \
    Media/Models/vallasPlastico_21.3ds \
    Media/Models/vallasPlastico_20.3ds \
    Media/Models/vallasPlastico_19.3ds \
    Media/Models/vallasPlastico_18.3ds \
    Media/Models/vallasPlastico_17.3ds \
    Media/Models/vallasPlastico_16.3ds \
    Media/Models/vallasPlastico_15.3ds \
    Media/Models/vallasPlastico_14.3ds \
    Media/Models/vallasPlastico_13.3ds \
    Media/Models/vallasPlastico_12.3ds \
    Media/Models/vallasPlastico_11.3ds \
    Media/Models/vallasPlastico_10.3ds \
    Media/Models/vallasPlastico_9.3ds \
    Media/Models/vallasPlastico_8.3ds \
    Media/Models/vallasPlastico_7.3ds \
    Media/Models/vallasPlastico_6.3ds \
    Media/Models/vallasPlastico_5.3ds \
    Media/Models/vallasPlastico_4.3ds \
    Media/Models/vallasPlastico_3.3ds \
    Media/Models/vallasPlastico_2.3ds \
    Media/Models/vallasPlastico_1.3ds \
    Media/Models/vallas_28.3ds \
    Media/Models/vallas_27.3ds \
    Media/Models/vallas_26.3ds \
    Media/Models/vallas_25.3ds \
    Media/Models/vallas_24.3ds \
    Media/Models/vallas_23.3ds \
    Media/Models/vallas_22.3ds \
    Media/Models/vallas_21.3ds \
    Media/Models/vallas_20.3ds \
    Media/Models/vallas_19.3ds \
    Media/Models/vallas_18.3ds \
    Media/Models/vallas_17.3ds \
    Media/Models/vallas_16.3ds \
    Media/Models/vallas_15.3ds \
    Media/Models/vallas_14.3ds \
    Media/Models/vallas_13.3ds \
    Media/Models/vallas_12.3ds \
    Media/Models/vallas_11.3ds \
    Media/Models/vallas_10.3ds \
    Media/Models/vallas_9.3ds \
    Media/Models/vallas_8.3ds \
    Media/Models/vallas_7.3ds \
    Media/Models/vallas_6.3ds \
    Media/Models/vallas_5.3ds \
    Media/Models/vallas_4.3ds \
    Media/Models/vallas_3.3ds \
    Media/Models/vallas_2.3ds \
    Media/Models/vallas_1.3ds \
    Media/Models/vallas.3ds \
    Media/Models/universal_2d_refmap.dds \
    Media/Models/unive003.dds \
    Media/Models/ubs_terrain_a.dds \
    Media/Models/ubs_decal_a.dds \
    Media/Models/ubs_d011.dds \
    Media/Models/ubs_board_a.dds \
    Media/Models/ubs_b004.dds \
    Media/Models/tyre_specocc.png \
    Media/Models/tyre_nm.png \
    Media/Models/tyre.tga \
    Media/Models/tyre.png \
    Media/Models/tread_slick_specocc.png \
    Media/Models/tread_slick_nm.png \
    Media/Models/tread_slick.tga \
    Media/Models/tread_slick.png \
    Media/Models/track_weteffects.dds \
    Media/Models/track_skidmarks_long.dds \
    Media/Models/track_marbles.dds \
    Media/Models/track_macro_a_02_d.dds \
    Media/Models/track_diff_a_02_d.dds \
    Media/Models/toilet_block_a.dds \
    Media/Models/toile025.dds \
    Media/Models/terrain.3ds \
    Media/Models/team_specific_monitors_d.dds \
    Media/Models/team_specific_garage_high_d.dds \
    Media/Models/team_065.dds \
    Media/Models/step_ladder_01_a.dds \
    Media/Models/standee_parcfermeplace_a_01_s.dds \
    Media/Models/standee_parcfermeplace_a_01_d.dds \
    Media/Models/stand107.dds \
    Media/Models/sponsorx_cats_varpl_d.dds \
    Media/Models/sponsorx_cats_varpk_d.dds \
    Media/Models/sponsorx_cats_varpj_d.dds \
    Media/Models/sponsorx_cats_varpi_d.dds \
    Media/Models/sponsorx_cats_varph_d.dds \
    Media/Models/sponsorx_cats_varpg_d.dds \
    Media/Models/sponsorx_cats_varpf_d.dds \
    Media/Models/sponsorx_cats_varpe_d.dds \
    Media/Models/sponsorx_cats_varpd_d.dds \
    Media/Models/sponsorx_cats_varpc_d.dds \
    Media/Models/sponsorx_cats_varpb_d.dds \
    Media/Models/sponsorx_cats_varpa_d.dds \
    Media/Models/sponsorx_cats_varca_d.dds \
    Media/Models/sponsorx_cats_varbv_d.dds \
    Media/Models/sponsor_racc_floor_01_d.dds \
    Media/Models/sponsor_circuit_catalunya_a_02_d.dds \
    Media/Models/sponsor_circuit_catalunya_a_01_d.dds \
    Media/Models/sponsor_backboard_01.dds \
    Media/Models/spons102.dds \
    Media/Models/spons082.dds \
    Media/Models/spons064.dds \
    Media/Models/spons022.dds \
    Media/Models/spons021.dds \
    Media/Models/speed_marker_01_d.dds \
    Media/Models/speed_marker_01_a.dds \
    Media/Models/speed098.dds \
    Media/Models/sky.3ds \
    Media/Models/sign_brakevertical_a_01_s.dds \
    Media/Models/sign_brakevertical_a_01_d.dds \
    Media/Models/sign_brakevertical_a_01_a.dds \
    Media/Models/sign_brakepole100_a_s.dds \
    Media/Models/sign_brakepole100_a_d.dds \
    Media/Models/sign_brakepole100_a_a.dds \
    Media/Models/sign_193.dds \
    Media/Models/sign_154.dds \
    Media/Models/sign_093.dds \
    Media/Models/sign_60mphmarker_a_01_s.dds \
    Media/Models/sign_60mphmarker_a_01_d.dds \
    Media/Models/sign_60mphmarker_a_01_a.dds \
    Media/Models/santander_terrain_a.dds \
    Media/Models/santander_brake_a.dds \
    Media/Models/santander_a.dds \
    Media/Models/santa019.dds \
    Media/Models/santa013.dds \
    Media/Models/safetywall_grey_a_01_s.dds \
    Media/Models/safetywall_grey_a_01_d.dds \
    Media/Models/safet069.dds \
    Media/Models/randomnoise.dds \
    Media/Models/rack_nosecone_a_01_a.dds \
    Media/Models/pzero_board_a.dds \
    Media/Models/pzero028.dds \
    Media/Models/poplar_tree_02_tr_d.dds \
    Media/Models/poplar_tree_02_shadow.dds \
    Media/Models/poplar_tree_02_lod_n.dds \
    Media/Models/poplar_tree_02_lod_d.dds \
    Media/Models/poplar_tree_02_fo_d.dds \
    Media/Models/poplar_tree_02_br_d.dds \
    Media/Models/poplar_tree_01_tr_d.dds \
    Media/Models/poplar_tree_01_shadow_d.dds \
    Media/Models/poplar_tree_01_lod_n.dds \
    Media/Models/poplar_tree_01_lod_d.dds \
    Media/Models/poplar_tree_01_fo_d.dds \
    Media/Models/popla081.dds \
    Media/Models/popla080.dds \
    Media/Models/popla078.dds \
    Media/Models/popla077.dds \
    Media/Models/popla064.dds \
    Media/Models/popla063.dds \
    Media/Models/popla060.dds \
    Media/Models/popla048.dds \
    Media/Models/placeholder_ipr.dds \
    Media/Models/pit_p113.dds \
    Media/Models/pit_p111.dds \
    Media/Models/pit_p106.dds \
    Media/Models/pit_p103.dds \
    Media/Models/pit_p102.dds \
    Media/Models/pit_p095.dds \
    Media/Models/pit_p094.dds \
    Media/Models/pit_p093.dds \
    Media/Models/pit_p077.dds \
    Media/Models/pit_p074.dds \
    Media/Models/pit_p067.dds \
    Media/Models/pit_p036.dds \
    Media/Models/pit_barrier_white_a_s.dds \
    Media/Models/pit_barrier_white_a_n.dds \
    Media/Models/pit_barrier_white_a_a.dds \
    Media/Models/pit_barrier_white_a.dds \
    Media/Models/pirelli_terrain_a.dds \
    Media/Models/pirelli_board_a.dds \
    Media/Models/pirel015.dds \
    Media/Models/pine_tree_01_tr_d.dds \
    Media/Models/pine_tree_01_shadow.dds \
    Media/Models/pine_tree_01_lod_n.dds \
    Media/Models/pine_tree_01_lod_d.dds \
    Media/Models/pine_tree_01_fo_d.dds \
    Media/Models/pine_tree_01_br_d.dds \
    Media/Models/physical_tyres_base_a_01_s.dds \
    Media/Models/physical_tyres_a_01_a.dds \
    Media/Models/pffloor_tarmac_a_02_s.dds \
    Media/Models/pffloor_tarmac_a_02_d.dds \
    Media/Models/pffloor_tarmac_a_01_d.dds \
    Media/Models/parcferme_macro.dds \
    Media/Models/objects_20.3ds \
    Media/Models/objects_19.3ds \
    Media/Models/objects_18.3ds \
    Media/Models/objects_17.3ds \
    Media/Models/objects_16.3ds \
    Media/Models/objects_15.3ds \
    Media/Models/objects_14.3ds \
    Media/Models/objects_13.3ds \
    Media/Models/objects_12.3ds \
    Media/Models/objects_11.3ds \
    Media/Models/objects_10.3ds \
    Media/Models/objects_9.3ds \
    Media/Models/objects_8.3ds \
    Media/Models/objects_7.3ds \
    Media/Models/objects_6.3ds \
    Media/Models/objects_5.3ds \
    Media/Models/objects_4.3ds \
    Media/Models/objects_3.3ds \
    Media/Models/objects_2.3ds \
    Media/Models/objects_1.3ds \
    Media/Models/objects1.3ds \
    Media/Models/oak_tree_03_shadow.dds \
    Media/Models/oak_tree_03_lod_n.dds \
    Media/Models/oak_tree_03_lod_d.dds \
    Media/Models/oak_tree_02_fo_d.dds \
    Media/Models/oak_tree_01_tr_d.dds \
    Media/Models/oak_tree_01_fo_d.dds \
    Media/Models/oak_t111.dds \
    Media/Models/oak_t110.dds \
    Media/Models/oak_t106.dds \
    Media/Models/oak_t094.dds \
    Media/Models/oak_t077.dds \
    Media/Models/monitorstation_white_c_01_a.dds \
    Media/Models/monitorstation_white_a_02_s.dds \
    Media/Models/monitorstation_white_a_01_s.dds \
    Media/Models/monitorstation_white_a_01_d.dds \
    Media/Models/mel_tarmac_a_01_n.dds \
    Media/Models/mel_tarmac_a_01_d.dds \
    Media/Models/marquee_truck_a_a.dds \
    Media/Models/marquee_truck_a_01_s.dds \
    Media/Models/marquee_truck_a_01_d.dds \
    Media/Models/marquee_sml_b_01_a.dds \
    Media/Models/marquee_sml_a_01_a.dds \
    Media/Models/marquee_a_01_s.dds \
    Media/Models/marquee_a_01_d.dds \
    Media/Models/marqu111.dds \
    Media/Models/macro_cloth_a_s.dds \
    Media/Models/macro_cloth_a_d.dds \
    Media/Models/macro_board_b_s.dds \
    Media/Models/macro_board_blank_d.dds \
    Media/Models/macro_board_b_d.dds \
    Media/Models/macro_board_a_s.dds \
    Media/Models/macro_board_a_d.dds \
    Media/Models/macro_block_a_d.dds \
    Media/Models/macro002.dds \
    Media/Models/lowgarage_team_lm_02.dds \
    Media/Models/lowgarage_team_lm_01.dds \
    Media/Models/light_pole_a_a.dds \
    Media/Models/light_glow.tga \
    Media/Models/light_glow.png \
    Media/Models/light_auxrace_a_01_s.dds \
    Media/Models/light_auxrace_a_01_d.dds \
    Media/Models/light_auxrace_a_01_a.dds \
    Media/Models/light105.dds \
    Media/Models/lg_pit_exit_light_a_01_s.dds \
    Media/Models/lg_pit_exit_light_a_01_d.dds \
    Media/Models/lg_pit_exit_light_a_01_a.dds \
    Media/Models/lg_pi086.dds \
    Media/Models/lg_marshal_light_a_01_s.dds \
    Media/Models/lg_marshal_light_a_01_d.dds \
    Media/Models/lg_marshal_light_a_01_a.dds \
    Media/Models/lg_ma109.dds \
    Media/Models/lg_board_a.dds \
    Media/Models/lg_bo012.dds \
    Media/Models/jumbotron_screeneffect_d.dds \
    Media/Models/jumbotron_b_a_a.dds \
    Media/Models/jumbotron_b_01_s.dds \
    Media/Models/jumbotron_b_01_d.dds \
    Media/Models/jumbo076.dds \
    Media/Models/int_led.tga \
    Media/Models/int_led.png \
    Media/Models/int_info_pod.tga \
    Media/Models/int_info_pod.png \
    Media/Models/int_indicator.tga \
    Media/Models/int_indicator.png \
    Media/Models/int_fe0_main.tga \
    Media/Models/int_fe0_main.png \
    Media/Models/int_digi_tach.tga \
    Media/Models/int_digi_tach.png \
    Media/Models/int_digi_placeholder.tga \
    Media/Models/int_digi_placeholder.png \
    Media/Models/hut_marshall_a_s.dds \
    Media/Models/hut_marshall_a_d.dds \
    Media/Models/hut_marshall_a_01_a.dds \
    Media/Models/hut_m023.dds \
    Media/Models/hedge_medium_main_b_02_s.dds \
    Media/Models/hedge_medium_main_b_02_d.dds \
    Media/Models/hedge_medium_main_b_01_d.dds \
    Media/Models/hedge131.dds \
    Media/Models/hedge130.dds \
    Media/Models/gs_cl014.dds \
    Media/Models/gradas8.3ds \
    Media/Models/gradas7.3ds \
    Media/Models/gradas6.3ds \
    Media/Models/gradas5.3ds \
    Media/Models/gradas4.3ds \
    Media/Models/gradas3.3ds \
    Media/Models/gradas2.3ds \
    Media/Models/gradas1.3ds \
    Media/Models/glass.tga \
    Media/Models/glass.png \
    Media/Models/generic_occlusion_01_a.dds \
    Media/Models/generic_main_specocc.png \
    Media/Models/generic_main_nm.png \
    Media/Models/generic_main.tga \
    Media/Models/generic_main.png \
    Media/Models/garage_team_reflection_a_01_d.dds \
    Media/Models/garage_team_colour_a_01_s.dds \
    Media/Models/garage_team_a.dds \
    Media/Models/garage_pit_decal_a_01_s.dds \
    Media/Models/garage_pit_decal_a_01_d.dds \
    Media/Models/garage_low_varq_d.dds \
    Media/Models/garage_low_varp_d.dds \
    Media/Models/garage_low_varo_d.dds \
    Media/Models/garage_low_varn_d.dds \
    Media/Models/garage_low_varm_d.dds \
    Media/Models/garage_low_varl_d.dds \
    Media/Models/garage_low_vark_d.dds \
    Media/Models/garage_low_varj_d.dds \
    Media/Models/garage_low_vari_d.dds \
    Media/Models/garage_low_varh_d.dds \
    Media/Models/garage_low_varg_d.dds \
    Media/Models/garage_low_varf_d.dds \
    Media/Models/garage_low_vare_d.dds \
    Media/Models/garage_building_interior_a_01_s.dds \
    Media/Models/garage_building_interior_a_01_n.dds \
    Media/Models/garage_building_interior_a_01_d.dds \
    Media/Models/garage_building_interior_a_01_a.dds \
    Media/Models/garage_building_a.dds \
    Media/Models/garag147.dds \
    Media/Models/garag087.dds \
    Media/Models/garag029.dds \
    Media/Models/garag028.dds \
    Media/Models/garag027.dds \
    Media/Models/garag026.dds \
    Media/Models/garag025.dds \
    Media/Models/garag024.dds \
    Media/Models/garag023.dds \
    Media/Models/garag022.dds \
    Media/Models/garag021.dds \
    Media/Models/garag020.dds \
    Media/Models/garag019.dds \
    Media/Models/garag018.dds \
    Media/Models/garag017.dds \
    Media/Models/gantry_start_a_01_d.dds \
    Media/Models/gantry_overhang_a_01_a.dds \
    Media/Models/gantr064.dds \
    Media/Models/forest4.3ds \
    Media/Models/forest3.3ds \
    Media/Models/forest2.3ds \
    Media/Models/forest1.3ds \
    Media/Models/flag_scrolling_spa_01_d.dds \
    Media/Models/flag_scrolling_mon_01_d.dds \
    Media/Models/flag_scrolling_ger_01_d.dds \
    Media/Models/flag_scrolling_fer_01_d.dds \
    Media/Models/flag_scrolling_eng_01_d.dds \
    Media/Models/flag_scrolling_bra_01_d.dds \
    Media/Models/flag_scrolling_bla_01_d.dds \
    Media/Models/flag_106.dds \
    Media/Models/flag_100.dds \
    Media/Models/flag_095.dds \
    Media/Models/flag_092.dds \
    Media/Models/flag_091.dds \
    Media/Models/flag_085.dds \
    Media/Models/flag_079.dds \
    Media/Models/ferrari.3ds \
    Media/Models/fencekit_a_01_s.dds \
    Media/Models/fencekit_a_01_d.dds \
    Media/Models/fence_concrete_base_a_mesh_01_d.dds \
    Media/Models/fence_concrete_base_a_01_s.dds \
    Media/Models/fence_concrete_base_a_01_d.dds \
    Media/Models/fence_concrete_base_a_01_a.dds \
    Media/Models/fence_barbed_main_a_mesh_01_s.dds \
    Media/Models/fence_barbed_main_a_mesh_01_d.dds \
    Media/Models/fence_barbed_b_01_s.dds \
    Media/Models/fence_barbed_b_01_d.dds \
    Media/Models/fence161.dds \
    Media/Models/fence152.dds \
    Media/Models/fence134.dds \
    Media/Models/fence125.dds \
    Media/Models/fe0_wheel.tga \
    Media/Models/fe0_wheel.png \
    Media/Models/fe0_main.tga \
    Media/Models/fe0_main.png \
    Media/Models/f1_jumbotron_logo_a_01_d.dds \
    Media/Models/f1_ju127.dds \
    Media/Models/eucalyptus_tree_01_tr_d.dds \
    Media/Models/eucalyptus_tree_01_shadow.dds \
    Media/Models/eucalyptus_tree_01_lod_n.dds \
    Media/Models/eucalyptus_tree_01_lod_d.dds \
    Media/Models/eucalyptus_tree_01_fo_d.dds \
    Media/Models/eucalyptus_tree_01_br_d.dds \
    Media/Models/eucal045.dds \
    Media/Models/eucal044.dds \
    Media/Models/eucal041.dds \
    Media/Models/eucal027.dds \
    Media/Models/eucal012.dds \
    Media/Models/eni_terrain_a.dds \
    Media/Models/eni_board_a.dds \
    Media/Models/eni_b010.dds \
    Media/Models/drs_w029.dds \
    Media/Models/distance_firbeech_02_fo_d.dds \
    Media/Models/distance_firbeech_01_fo_d.dds \
    Media/Models/dista118.dds \
    Media/Models/dista117.dds \
    Media/Models/dista069.dds \
    Media/Models/dista038.dds \
    Media/Models/digi6.tga \
    Media/Models/digi5.tga \
    Media/Models/digi4.tga \
    Media/Models/digi3.tga \
    Media/Models/digi2.tga \
    Media/Models/digi1.tga \
    Media/Models/dhl_board_a.dds \
    Media/Models/dhl_b014.dds \
    Media/Models/defaultrefmap.dds \
    Media/Models/default_ao_terrain.dds \
    Media/Models/default_ao.dds \
    Media/Models/crowd_flag_lrg_a_03_s.dds \
    Media/Models/core_start_lights_gantry_a_a.dds \
    Media/Models/core_start_lights_a_01_s.dds \
    Media/Models/core_start_lights_a_01_d.dds \
    Media/Models/core_start_lights_a_01_a.dds \
    Media/Models/core_069.dds \
    Media/Models/conc_bollard_filler_a_01_s.dds \
    Media/Models/conc_bollard_filler_a_01_d.dds \
    Media/Models/conc_116.dds \
    Media/Models/clear120.dds \
    Media/Models/chasis2.tga \
    Media/Models/chasis.tga \
    Media/Models/chasis.3ds \
    Media/Models/cat_w025.dds \
    Media/Models/cat_verge_e_n.dds \
    Media/Models/cat_verge_e_d.dds \
    Media/Models/cat_verge_d_n.dds \
    Media/Models/cat_verge_d_d.dds \
    Media/Models/cat_verge_c_n.dds \
    Media/Models/cat_verge_c_d.dds \
    Media/Models/cat_verge_b_n.dds \
    Media/Models/cat_verge_b_d.dds \
    Media/Models/cat_verge_a_n.dds \
    Media/Models/cat_verge_a_d.dds \
    Media/Models/cat_v008.dds \
    Media/Models/cat_v007.dds \
    Media/Models/cat_v006.dds \
    Media/Models/cat_v005.dds \
    Media/Models/cat_v004.dds \
    Media/Models/cat_tracksurface_n.dds \
    Media/Models/cat_track_lines_a_01_s.dds \
    Media/Models/cat_track_lines_a_01_n.dds \
    Media/Models/cat_track_lines_a_01_d.dds \
    Media/Models/cat_tarmac_new_wsm_a_s.dds \
    Media/Models/cat_tarmac_new_wsm_a_d.dds \
    Media/Models/cat_tarmac_a_03_offtrack_d.dds \
    Media/Models/cat_tarmac_a_02_d.dds \
    Media/Models/cat_t133.dds \
    Media/Models/cat_t132.dds \
    Media/Models/cat_soil_a_d.dds \
    Media/Models/cat_sky_sun_01.dds \
    Media/Models/cat_s003.dds \
    Media/Models/cat_rnf_wht_a_d.dds \
    Media/Models/cat_rnf_tile_a_n.dds \
    Media/Models/cat_rnf_tile_a_d.dds \
    Media/Models/cat_rnf_red_a_s.dds \
    Media/Models/cat_rnf_red_a_n.dds \
    Media/Models/cat_rnf_red_a_d.dds \
    Media/Models/cat_rnf_grn_wsm_b_d.dds \
    Media/Models/cat_rnf_grn_wsm_a_s.dds \
    Media/Models/cat_rnf_grn_wsm_a_d.dds \
    Media/Models/cat_rnf_cpt_a_n.dds \
    Media/Models/cat_rnf_cpt_a_d.dds \
    Media/Models/cat_r023.dds \
    Media/Models/cat_r015.dds \
    Media/Models/cat_r009.dds \
    Media/Models/cat_r003.dds \
    Media/Models/cat_post_tannoy_a_01_d.dds \
    Media/Models/cat_post_tannoy_a_01_a.dds \
    Media/Models/cat_pole_wires_a_s.dds \
    Media/Models/cat_pole_wires_a_d.dds \
    Media/Models/cat_pole_wires_a_01_a.dds \
    Media/Models/cat_pole_ranking_a_01_s.dds \
    Media/Models/cat_pole_ranking_a_01_d.dds \
    Media/Models/cat_pole_ranking_a_01_a.dds \
    Media/Models/cat_pole_comms_a_01_s.dds \
    Media/Models/cat_pole_comms_a_01_d.dds \
    Media/Models/cat_pole_comms_a_01_a.dds \
    Media/Models/cat_pole_belltop_a_01_d.dds \
    Media/Models/cat_pole_belltop_a_01_a.dds \
    Media/Models/cat_pitwall_a_01_s.dds \
    Media/Models/cat_pitwall_a_01_n.dds \
    Media/Models/cat_pitwall_a_01_d.dds \
    Media/Models/cat_pitwall_a_01_a.dds \
    Media/Models/cat_p110.dds \
    Media/Models/cat_p107.dds \
    Media/Models/cat_p103.dds \
    Media/Models/cat_p102.dds \
    Media/Models/cat_p066.dds \
    Media/Models/cat_p021.dds \
    Media/Models/cat_o098.dds \
    Media/Models/cat_micromacrowsm_01_spons.dds \
    Media/Models/cat_micromacrowsm_01_d.dds \
    Media/Models/cat_macro_terrain_01_d.dds \
    Media/Models/cat_macro_shine_d.dds \
    Media/Models/cat_macro_grs_d.dds \
    Media/Models/cat_m014.dds \
    Media/Models/cat_landscape_d.dds \
    Media/Models/cat_infrastructure_westwall_a_01_d.dds \
    Media/Models/cat_infrastructure_westwall_a_01_a.dds \
    Media/Models/cat_infrastructure_weststair_a_01_s.dds \
    Media/Models/cat_infrastructure_weststair_a_01_d.dds \
    Media/Models/cat_infrastructure_weststair_a_01_a.dds \
    Media/Models/cat_infrastructure_rockbolster_a_01_a.dds \
    Media/Models/cat_infrastructure_jumbotron_a_01_s.dds \
    Media/Models/cat_infrastructure_jumbotron_a_01_d.dds \
    Media/Models/cat_infrastructure_jumbotron_a_01_a.dds \
    Media/Models/cat_infield_b_01_d.dds \
    Media/Models/cat_infield_a_02_s.dds \
    Media/Models/cat_infield_a_02_d.dds \
    Media/Models/cat_i136.dds \
    Media/Models/cat_i011.dds \
    Media/Models/cat_i005.dds \
    Media/Models/cat_i001.dds \
    Media/Models/cat_hut_greysweep_a_01_s.dds \
    Media/Models/cat_hut_greysweep_a_01_d.dds \
    Media/Models/cat_hut_greysweep_a_01_a.dds \
    Media/Models/cat_hut_greyplatform_a_01_a.dds \
    Media/Models/cat_h067.dds \
    Media/Models/cat_gvl_wsm_a_s.dds \
    Media/Models/cat_gvl_wsm_a_d.dds \
    Media/Models/cat_gvl_a_s.dds \
    Media/Models/cat_gvl_a_d.dds \
    Media/Models/cat_grs_tmc_b_d.dds \
    Media/Models/cat_grs_tmc_a_d.dds \
    Media/Models/cat_grs_dry_wsm_a_n.dds \
    Media/Models/cat_grs_dry_wsm_a_d.dds \
    Media/Models/cat_grandstand_vipseats_a_01_a.dds \
    Media/Models/cat_grandstand_vipseats_01_d.dds \
    Media/Models/cat_grandstand_twosided_a_01_a.dds \
    Media/Models/cat_grandstand_tribuna_a_06_d.dds \
    Media/Models/cat_grandstand_tribuna_a_05_d.dds \
    Media/Models/cat_grandstand_tribuna_a_04_s.dds \
    Media/Models/cat_grandstand_tribuna_a_04_d.dds \
    Media/Models/cat_grandstand_tribuna_a_03_s.dds \
    Media/Models/cat_grandstand_tribuna_a_03_d.dds \
    Media/Models/cat_grandstand_tribuna_a_02_s.dds \
    Media/Models/cat_grandstand_tribuna_a_02_d.dds \
    Media/Models/cat_grandstand_tribuna_a_01_s.dds \
    Media/Models/cat_grandstand_tribuna_a_01_d.dds \
    Media/Models/cat_grandstand_tribuna_a_01_a.dds \
    Media/Models/cat_grandstand_o_01_a.dds \
    Media/Models/cat_grandstand_n_01_a.dds \
    Media/Models/cat_grandstand_m_01_a.dds \
    Media/Models/cat_grandstand_lastcorner_a_01_s.dds \
    Media/Models/cat_grandstand_lastcorner_a_01_d.dds \
    Media/Models/cat_grandstand_lastcorner_a_01_a.dds \
    Media/Models/cat_grandstand_l_01_a.dds \
    Media/Models/cat_grandstand_j_01_a_.dds \
    Media/Models/cat_grandstand_i_01_a.dds \
    Media/Models/cat_grandstand_hillside_a_02_s.dds \
    Media/Models/cat_grandstand_hillside_a_02_n.dds \
    Media/Models/cat_grandstand_hillside_a_02_d.dds \
    Media/Models/cat_grandstand_hillside_a_01_s.dds \
    Media/Models/cat_grandstand_hillside_a_01_n.dds \
    Media/Models/cat_grandstand_hillside_a_01_d.dds \
    Media/Models/cat_grandstand_hillside_a_01_a.dds \
    Media/Models/cat_grandstand_h_01_a.dds \
    Media/Models/cat_grandstand_g_01_d.dds \
    Media/Models/cat_grandstand_g_01_a.dds \
    Media/Models/cat_grandstand_frameroof_a_01_s.dds \
    Media/Models/cat_grandstand_frameroof_a_01_n.dds \
    Media/Models/cat_grandstand_frameroof_a_01_d.dds \
    Media/Models/cat_grandstand_frameroof_a_01_a.dds \
    Media/Models/cat_grandstand_f_01_a.dds \
    Media/Models/cat_grandstand_e_01_a.dds \
    Media/Models/cat_grandstand_doubledeck_a_01_a.dds \
    Media/Models/cat_grandstand_d_01_a.dds \
    Media/Models/cat_grandstand_c_01_a.dds \
    Media/Models/cat_grandstand_b_01_a.dds \
    Media/Models/cat_grandstand_a_04_d.dds \
    Media/Models/cat_grandstand_a_03_d.dds \
    Media/Models/cat_grandstand_a_02_d.dds \
    Media/Models/cat_grandstand_a_01_s.dds \
    Media/Models/cat_grandstand_a_01_d.dds \
    Media/Models/cat_grandstand_a_01_a.dds \
    Media/Models/cat_generic_flat_normal_n.dds \
    Media/Models/cat_g115.dds \
    Media/Models/cat_g114.dds \
    Media/Models/cat_g113.dds \
    Media/Models/cat_g112.dds \
    Media/Models/cat_g109.dds \
    Media/Models/cat_g101.dds \
    Media/Models/cat_g100.dds \
    Media/Models/cat_g089.dds \
    Media/Models/cat_g087.dds \
    Media/Models/cat_g086.dds \
    Media/Models/cat_g085.dds \
    Media/Models/cat_g084.dds \
    Media/Models/cat_g083.dds \
    Media/Models/cat_g082.dds \
    Media/Models/cat_g068.dds \
    Media/Models/cat_g054.dds \
    Media/Models/cat_g037.dds \
    Media/Models/cat_g010.dds \
    Media/Models/cat_g009.dds \
    Media/Models/cat_g001.dds \
    Media/Models/cat_g000.dds \
    Media/Models/cat_furniture_redbin_a_01_a.dds \
    Media/Models/cat_furniture_hillbench_a_01_d.dds \
    Media/Models/cat_furniture_hillbench_a_01_a.dds \
    Media/Models/cat_flag_01_d.dds \
    Media/Models/cat_fea_a_d.dds \
    Media/Models/cat_f135.dds \
    Media/Models/cat_f076.dds \
    Media/Models/cat_f039.dds \
    Media/Models/cat_edgestrips_a_s.dds \
    Media/Models/cat_edgestrips_a_n.dds \
    Media/Models/cat_edgestrips_a_d.dds \
    Media/Models/cat_e022.dds \
    Media/Models/cat_details_e_n.dds \
    Media/Models/cat_details_e_d.dds \
    Media/Models/cat_details_d_n.dds \
    Media/Models/cat_details_d_d.dds \
    Media/Models/cat_details_c_n.dds \
    Media/Models/cat_details_c_d.dds \
    Media/Models/cat_details_c_01_n.dds \
    Media/Models/cat_details_c_01_d.dds \
    Media/Models/cat_details_b_n.dds \
    Media/Models/cat_details_b_d.dds \
    Media/Models/cat_details_a_n.dds \
    Media/Models/cat_details_a_flat_d.dds \
    Media/Models/cat_details_a_d.dds \
    Media/Models/cat_d124.dds \
    Media/Models/cat_d052.dds \
    Media/Models/cat_d037.dds \
    Media/Models/cat_d035.dds \
    Media/Models/cat_d008.dds \
    Media/Models/cat_d007.dds \
    Media/Models/cat_d006.dds \
    Media/Models/cat_d005.dds \
    Media/Models/cat_cnc_wsm_a_s.dds \
    Media/Models/cat_cnc_wsm_a_d.dds \
    Media/Models/cat_c005.dds \
    Media/Models/cat_building_villa_a_01_s.dds \
    Media/Models/cat_building_villa_a_01_d.dds \
    Media/Models/cat_building_villa_a_01_a.dds \
    Media/Models/cat_building_podium_a_01_s.dds \
    Media/Models/cat_building_podium_a_01_n.dds \
    Media/Models/cat_building_podium_a_01_d.dds \
    Media/Models/cat_building_podium_a_01_a.dds \
    Media/Models/cat_building_pittower_a_01_s.dds \
    Media/Models/cat_building_pittower_a_01_d.dds \
    Media/Models/cat_building_pittower_a_01_a.dds \
    Media/Models/cat_building_pitgarages_a_06_s.dds \
    Media/Models/cat_building_pitgarages_a_06_n.dds \
    Media/Models/cat_building_pitgarages_a_06_d.dds \
    Media/Models/cat_building_pitgarages_a_05_s.dds \
    Media/Models/cat_building_pitgarages_a_05_n.dds \
    Media/Models/cat_building_pitgarages_a_05_d.dds \
    Media/Models/cat_building_pitgarages_a_04_s.dds \
    Media/Models/cat_building_pitgarages_a_04_n.dds \
    Media/Models/cat_building_pitgarages_a_04_d.dds \
    Media/Models/cat_building_pitgarages_a_03_s.dds \
    Media/Models/cat_building_pitgarages_a_03_n.dds \
    Media/Models/cat_building_pitgarages_a_03_d.dds \
    Media/Models/cat_building_pitgarages_a_02_s.dds \
    Media/Models/cat_building_pitgarages_a_02_n.dds \
    Media/Models/cat_building_pitgarages_a_02_d.dds \
    Media/Models/cat_building_pitgarages_a_01_s.dds \
    Media/Models/cat_building_pitgarages_a_01_n.dds \
    Media/Models/cat_building_pitgarages_a_01_d.dds \
    Media/Models/cat_building_pitgarages_a_01_a.dds \
    Media/Models/cat_building_partyhouse_a_01_s.dds \
    Media/Models/cat_building_partyhouse_a_01_d.dds \
    Media/Models/cat_building_partyhouse_a_01_a.dds \
    Media/Models/cat_bridge_west_a_01_s.dds \
    Media/Models/cat_bridge_west_a_01_n.dds \
    Media/Models/cat_bridge_west_a_01_d.dds \
    Media/Models/cat_bridge_west_a_01_a.dds \
    Media/Models/cat_bridge_startfinish_a_01_s.dds \
    Media/Models/cat_bridge_startfinish_a_01_d.dds \
    Media/Models/cat_bridge_startfinish_a_01_a.dds \
    Media/Models/cat_bridge_junction_a_01_d.dds \
    Media/Models/cat_bridge_junction_a_01_a.dds \
    Media/Models/cat_bridge_hillcross_a_01_a.dds \
    Media/Models/cat_blend_c.dds \
    Media/Models/cat_blend_b.dds \
    Media/Models/cat_barrier_redtarp_a_01_s.dds \
    Media/Models/cat_barrier_redtarp_a_01_d.dds \
    Media/Models/cat_barrier_paddockfrontgate_a_01_s.dds \
    Media/Models/cat_barrier_paddockfrontgate_a_01_d.dds \
    Media/Models/cat_barrier_paddockfrontgate_a_01_a.dds \
    Media/Models/cat_barrier_paddockbacgate_a_01_s.dds \
    Media/Models/cat_barrier_paddockbacgate_a_01_d.dds \
    Media/Models/cat_barrier_paddockbacgate_a_01_a.dds \
    Media/Models/cat_banner_longframe_a_01_s.dds \
    Media/Models/cat_banner_longframe_a_01_d.dds \
    Media/Models/cat_banner_longframe_a_01_a.dds \
    Media/Models/cat_banner_greenframe_a_01_s.dds \
    Media/Models/cat_banner_greenframe_a_01_d.dds \
    Media/Models/cat_banner_greenframe_a_01_a.dds \
    Media/Models/cat_b138.dds \
    Media/Models/cat_b121.dds \
    Media/Models/cat_b115.dds \
    Media/Models/cat_b113.dds \
    Media/Models/cat_b112.dds \
    Media/Models/cat_b102.dds \
    Media/Models/cat_b100.dds \
    Media/Models/cat_b099.dds \
    Media/Models/cat_b098.dds \
    Media/Models/cat_b097.dds \
    Media/Models/cat_b096.dds \
    Media/Models/cat_b095.dds \
    Media/Models/cat_b086.dds \
    Media/Models/cat_b085.dds \
    Media/Models/cat_b063.dds \
    Media/Models/cat_b055.dds \
    Media/Models/cat_ao_terrain_01_d.dds \
    Media/Models/camera_scaffold_a_x2_a.dds \
    Media/Models/camera_scaffold_a_01_s.dds \
    Media/Models/camera_scaffold_a_01_d.dds \
    Media/Models/camer141.dds \
    Media/Models/buildings4_2.3ds \
    Media/Models/buildings4_1.3ds \
    Media/Models/buildings4.3ds \
    Media/Models/buildings3_7.3ds \
    Media/Models/buildings3_6.3ds \
    Media/Models/buildings3_5.3ds \
    Media/Models/buildings3_4.3ds \
    Media/Models/buildings3_3.3ds \
    Media/Models/buildings3_2.3ds \
    Media/Models/buildings3_1.3ds \
    Media/Models/buildings3.3ds \
    Media/Models/buildings2_4.3ds \
    Media/Models/buildings2_3.3ds \
    Media/Models/buildings2_2.3ds \
    Media/Models/buildings2_1.3ds \
    Media/Models/buildings2.3ds \
    Media/Models/buildings1_12.3ds \
    Media/Models/buildings1_11.3ds \
    Media/Models/buildings1_10.3ds \
    Media/Models/buildings1_9.3ds \
    Media/Models/buildings1_8.3ds \
    Media/Models/buildings1_7.3ds \
    Media/Models/buildings1_6.3ds \
    Media/Models/buildings1_5.3ds \
    Media/Models/buildings1_4.3ds \
    Media/Models/buildings1_3.3ds \
    Media/Models/buildings1_2.3ds \
    Media/Models/buildings1_1.3ds \
    Media/Models/brake_white_150_a.dds \
    Media/Models/brake_white_100_a.dds \
    Media/Models/brake_white_50_a.dds \
    Media/Models/brake_drs_a.dds \
    Media/Models/brake_black_blank_a.dds \
    Media/Models/brake162.dds \
    Media/Models/brake157.dds \
    Media/Models/brake103.dds \
    Media/Models/barreras_15.3ds \
    Media/Models/barreras_14.3ds \
    Media/Models/barreras_13.3ds \
    Media/Models/barreras_12.3ds \
    Media/Models/barreras_11.3ds \
    Media/Models/barreras_10.3ds \
    Media/Models/barreras_9.3ds \
    Media/Models/barreras_8.3ds \
    Media/Models/barreras_7.3ds \
    Media/Models/barreras_6.3ds \
    Media/Models/barreras_5.3ds \
    Media/Models/barreras_4.3ds \
    Media/Models/barreras_3.3ds \
    Media/Models/barreras_2.3ds \
    Media/Models/barreras_1.3ds \
    Media/Models/banner_crowdpartition_a_01_s.dds \
    Media/Models/banner_crowdpartition_a_01_d.dds \
    Media/Models/banne051.dds \
    Media/Models/banderas_17.3ds \
    Media/Models/banderas_16.3ds \
    Media/Models/banderas_15.3ds \
    Media/Models/banderas_14.3ds \
    Media/Models/banderas_13.3ds \
    Media/Models/banderas_12.3ds \
    Media/Models/banderas_11.3ds \
    Media/Models/banderas_10.3ds \
    Media/Models/banderas_9.3ds \
    Media/Models/banderas_8.3ds \
    Media/Models/banderas_7.3ds \
    Media/Models/banderas_6.3ds \
    Media/Models/banderas_5.3ds \
    Media/Models/banderas_4.3ds \
    Media/Models/banderas_3.3ds \
    Media/Models/banderas_2.3ds \
    Media/Models/banderas_1.3ds \
    Media/Models/armco_grey_main_a_01_s.dds \
    Media/Models/armco_grey_main_a_01_d.dds \
    Media/Models/armco107.dds \
    Media/Models/allianz_terrain_a.dds \
    Media/Models/allianz_decal_a.dds \
    Media/Models/allianz_brake_a.dds \
    Media/Models/allianz_board_b.dds \
    Media/Models/allianz_board_a.dds \
    Media/Models/allia010.dds \
    Media/Models/allia009.dds \
    Media/Models/allia006.dds \
    Media/Models/advert_side_a_s.dds \
    Media/Models/advert_side_a_d.dds \
    Media/Models/advert_side_a_a.dds \
    Media/Models/adver004.dds



LIBS += -lgomp

QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp

QMAKE_CFLAGS_RELEASE += -fopenmp
QMAKE_CFLAGS_DEBUG += -fopenmp


unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += assimp

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += IL
