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
    openGLwindow.cpp \
    glWidget.cpp \
    camera.cpp \
    Loaders/settingsexporter.cpp \
    Loaders/lightloader.cpp \
    Loaders/fileParser.cpp \
    Loaders/camerasloader.cpp \
    Ui/lightswindowqt.cpp \
    Ui/importsettingsqt.cpp \
    Ui/exportsettingsqt.cpp \
    Ui/errorwindow.cpp

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
    openGLwindow.h \
    ui_thothwindow.h \
    camera.h \
    glWidget.h \
    Loaders/settingsexporter.h \
    Loaders/lightloader.h \
    Loaders/fileParser.h \
    Loaders/camerasloader.h \
    Ui/lightswindowqt.h \
    Ui/importsettingsqt.h \
    Ui/exportsettingsqt.h \
    Ui/errorwindow.h

FORMS    += \
    openGLwindow.ui \
    Ui/montmelocircuit.ui \
    Ui/lightswindowqt.ui \
    Ui/importsettingsqt.ui \
    Ui/exportsettingsqt.ui \
    Ui/errorwindow.ui

OTHER_FILES += \
    simple.vert \
    simple.frag \
    Media/Images/car.png \
    Media/Images/1364340396_photography.png \
    Media/Images/1364340391_lightbulb.png \
    Media/Images/1364339878_hire-me.png \
    Media/Images/1364339322_logout.png \
    Media/Images/1364339241_sign-out.png \
    Media/Images/1364338876_sign-in.png \
    Media/Models/Circuit/ubs_decal_a.dds \
    Media/Models/Circuit/ubs_board_a.dds \
    Media/Models/Circuit/track_diff_a_02_d.dds \
    Media/Models/Circuit/toilet_block_a.dds \
    Media/Models/Circuit/team_specific_monitors_d.dds \
    Media/Models/Circuit/team_specific_garage_high_d.dds \
    Media/Models/Circuit/standee_parcfermeplace_a_01_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpl_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpk_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpj_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpi_d.dds \
    Media/Models/Circuit/sponsorx_cats_varph_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpg_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpf_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpe_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpd_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpc_d.dds \
    Media/Models/Circuit/sponsorx_cats_varpa_d.dds \
    Media/Models/Circuit/sponsorx_cats_varca_d.dds \
    Media/Models/Circuit/sponsorx_cats_varbv_d.dds \
    Media/Models/Circuit/speed_marker_01_d.dds \
    Media/Models/Circuit/sign_brakevertical_a_01_d.dds \
    Media/Models/Circuit/sign_brakepole100_a_d.dds \
    Media/Models/Circuit/sign_60mphmarker_a_01_d.dds \
    Media/Models/Circuit/santander_brake_a.dds \
    Media/Models/Circuit/safetywall_grey_a_01_d.dds \
    Media/Models/Circuit/poplar_tree_02_tr_d.dds \
    Media/Models/Circuit/poplar_tree_02_shadow.dds \
    Media/Models/Circuit/poplar_tree_02_lod_d.dds \
    Media/Models/Circuit/poplar_tree_02_fo_d.dds \
    Media/Models/Circuit/poplar_tree_02_br_d.dds \
    Media/Models/Circuit/poplar_tree_01_tr_d.dds \
    Media/Models/Circuit/poplar_tree_01_shadow_d.dds \
    Media/Models/Circuit/poplar_tree_01_lod_d.dds \
    Media/Models/Circuit/poplar_tree_01_fo_d.dds \
    Media/Models/Circuit/pit_barrier_white_a.dds \
    Media/Models/Circuit/pirelli_board_a.dds \
    Media/Models/Circuit/pine_tree_01_tr_d.dds \
    Media/Models/Circuit/pine_tree_01_shadow.dds \
    Media/Models/Circuit/pine_tree_01_lod_d.dds \
    Media/Models/Circuit/pine_tree_01_fo_d.dds \
    Media/Models/Circuit/pine_tree_01_br_d.dds \
    Media/Models/Circuit/pffloor_tarmac_a_02_d.dds \
    Media/Models/Circuit/pffloor_tarmac_a_01_d.dds \
    Media/Models/Circuit/oak_tree_03_shadow.dds \
    Media/Models/Circuit/oak_tree_03_lod_d.dds \
    Media/Models/Circuit/oak_tree_02_fo_d.dds \
    Media/Models/Circuit/oak_tree_01_tr_d.dds \
    Media/Models/Circuit/oak_tree_01_fo_d.dds \
    Media/Models/Circuit/monitorstation_white_a_01_d.dds \
    Media/Models/Circuit/mel_tarmac_a_01_d.dds \
    Media/Models/Circuit/marquee_truck_a_01_d.dds \
    Media/Models/Circuit/marquee_a_01_d.dds \
    Media/Models/Circuit/macro_cloth_a_d.dds \
    Media/Models/Circuit/macro_board_blank_d.dds \
    Media/Models/Circuit/macro_board_b_d.dds \
    Media/Models/Circuit/macro_board_a_d.dds \
    Media/Models/Circuit/light_auxrace_a_01_d.dds \
    Media/Models/Circuit/lg_pit_exit_light_a_01_d.dds \
    Media/Models/Circuit/lg_marshal_light_a_01_d.dds \
    Media/Models/Circuit/jumbotron_b_01_d.dds \
    Media/Models/Circuit/hut_marshall_a_d.dds \
    Media/Models/Circuit/hedge_medium_main_b_02_d.dds \
    Media/Models/Circuit/hedge_medium_main_b_01_d.dds \
    Media/Models/Circuit/garage_pit_decal_a_01_d.dds \
    Media/Models/Circuit/garage_low_varq_d.dds \
    Media/Models/Circuit/garage_low_varp_d.dds \
    Media/Models/Circuit/garage_low_varo_d.dds \
    Media/Models/Circuit/garage_low_varn_d.dds \
    Media/Models/Circuit/garage_low_varm_d.dds \
    Media/Models/Circuit/garage_low_varl_d.dds \
    Media/Models/Circuit/garage_low_vark_d.dds \
    Media/Models/Circuit/garage_low_varj_d.dds \
    Media/Models/Circuit/garage_low_vari_d.dds \
    Media/Models/Circuit/garage_low_varh_d.dds \
    Media/Models/Circuit/garage_low_varg_d.dds \
    Media/Models/Circuit/garage_low_varf_d.dds \
    Media/Models/Circuit/garage_low_vare_d.dds \
    Media/Models/Circuit/garage_building_interior_a_01_d.dds \
    Media/Models/Circuit/gantry_start_a_01_d.dds \
    Media/Models/Circuit/flag_scrolling_spa_01_d.dds \
    Media/Models/Circuit/flag_scrolling_mon_01_d.dds \
    Media/Models/Circuit/flag_scrolling_ger_01_d.dds \
    Media/Models/Circuit/flag_scrolling_fer_01_d.dds \
    Media/Models/Circuit/flag_scrolling_eng_01_d.dds \
    Media/Models/Circuit/flag_scrolling_bra_01_d.dds \
    Media/Models/Circuit/flag_scrolling_bla_01_d.dds \
    Media/Models/Circuit/fencekit_a_01_d.dds \
    Media/Models/Circuit/fence_concrete_base_a_mesh_01_d.dds \
    Media/Models/Circuit/fence_concrete_base_a_01_d.dds \
    Media/Models/Circuit/fence_barbed_main_a_mesh_01_d.dds \
    Media/Models/Circuit/fence_barbed_b_01_d.dds \
    Media/Models/Circuit/f1_jumbotron_logo_a_01_d.dds \
    Media/Models/Circuit/eucalyptus_tree_01_tr_d.dds \
    Media/Models/Circuit/eucalyptus_tree_01_shadow.dds \
    Media/Models/Circuit/eucalyptus_tree_01_lod_d.dds \
    Media/Models/Circuit/eucalyptus_tree_01_fo_d.dds \
    Media/Models/Circuit/eucalyptus_tree_01_br_d.dds \
    Media/Models/Circuit/distance_firbeech_02_fo_d.dds \
    Media/Models/Circuit/distance_firbeech_01_fo_d.dds \
    Media/Models/Circuit/dhl_board_a.dds \
    Media/Models/Circuit/core_start_lights_a_01_d.dds \
    Media/Models/Circuit/conc_bollard_filler_a_01_d.dds \
    Media/Models/Circuit/circuit.3ds \
    Media/Models/Circuit/cat_verge_e_d.dds \
    Media/Models/Circuit/cat_verge_d_d.dds \
    Media/Models/Circuit/cat_verge_c_d.dds \
    Media/Models/Circuit/cat_verge_b_d.dds \
    Media/Models/Circuit/cat_verge_a_d.dds \
    Media/Models/Circuit/cat_track_lines_a_01_d.dds \
    Media/Models/Circuit/cat_tarmac_a_03_offtrack_d.dds \
    Media/Models/Circuit/cat_tarmac_a_02_d.dds \
    Media/Models/Circuit/cat_soil_a_d.dds \
    Media/Models/Circuit/cat_rnf_wht_a_d.dds \
    Media/Models/Circuit/cat_rnf_tile_a_d.dds \
    Media/Models/Circuit/cat_rnf_red_a_d.dds \
    Media/Models/Circuit/cat_rnf_grn_wsm_a_d.dds \
    Media/Models/Circuit/cat_rnf_cpt_a_d.dds \
    Media/Models/Circuit/cat_post_tannoy_a_01_d.dds \
    Media/Models/Circuit/cat_pole_wires_a_d.dds \
    Media/Models/Circuit/cat_pole_ranking_a_01_d.dds \
    Media/Models/Circuit/cat_pole_comms_a_01_d.dds \
    Media/Models/Circuit/cat_pole_belltop_a_01_d.dds \
    Media/Models/Circuit/cat_pitwall_a_01_d.dds \
    Media/Models/Circuit/cat_micromacrowsm_01_spons.dds \
    Media/Models/Circuit/cat_macro_grs_d.dds \
    Media/Models/Circuit/cat_landscape_d.dds \
    Media/Models/Circuit/cat_infrastructure_westwall_a_01_d.dds \
    Media/Models/Circuit/cat_infrastructure_weststair_a_01_d.dds \
    Media/Models/Circuit/cat_infrastructure_jumbotron_a_01_d.dds \
    Media/Models/Circuit/cat_infield_a_02_d.dds \
    Media/Models/Circuit/cat_hut_greysweep_a_01_d.dds \
    Media/Models/Circuit/cat_gvl_a_d.dds \
    Media/Models/Circuit/cat_grs_tmc_b_d.dds \
    Media/Models/Circuit/cat_grs_tmc_a_d.dds \
    Media/Models/Circuit/cat_grs_dry_wsm_a_d.dds \
    Media/Models/Circuit/cat_grandstand_vipseats_01_d.dds \
    Media/Models/Circuit/cat_grandstand_tribuna_a_06_d.dds \
    Media/Models/Circuit/cat_grandstand_tribuna_a_05_d.dds \
    Media/Models/Circuit/cat_grandstand_tribuna_a_04_d.dds \
    Media/Models/Circuit/cat_grandstand_tribuna_a_03_d.dds \
    Media/Models/Circuit/cat_grandstand_tribuna_a_02_d.dds \
    Media/Models/Circuit/cat_grandstand_tribuna_a_01_d.dds \
    Media/Models/Circuit/cat_grandstand_lastcorner_a_01_d.dds \
    Media/Models/Circuit/cat_grandstand_hillside_a_02_d.dds \
    Media/Models/Circuit/cat_grandstand_hillside_a_01_d.dds \
    Media/Models/Circuit/cat_grandstand_g_01_d.dds \
    Media/Models/Circuit/cat_grandstand_frameroof_a_01_d.dds \
    Media/Models/Circuit/cat_grandstand_a_04_d.dds \
    Media/Models/Circuit/cat_grandstand_a_03_d.dds \
    Media/Models/Circuit/cat_grandstand_a_02_d.dds \
    Media/Models/Circuit/cat_grandstand_a_01_d.dds \
    Media/Models/Circuit/cat_furniture_hillbench_a_01_d.dds \
    Media/Models/Circuit/cat_flag_01_d.dds \
    Media/Models/Circuit/cat_fea_a_d.dds \
    Media/Models/Circuit/cat_edgestrips_a_d.dds \
    Media/Models/Circuit/cat_details_e_d.dds \
    Media/Models/Circuit/cat_details_d_d.dds \
    Media/Models/Circuit/cat_details_c_d.dds \
    Media/Models/Circuit/cat_details_c_01_d.dds \
    Media/Models/Circuit/cat_details_b_d.dds \
    Media/Models/Circuit/cat_details_a_flat_d.dds \
    Media/Models/Circuit/cat_details_a_d.dds \
    Media/Models/Circuit/cat_cnc_wsm_a_d.dds \
    Media/Models/Circuit/cat_building_villa_a_01_d.dds \
    Media/Models/Circuit/cat_building_podium_a_01_d.dds \
    Media/Models/Circuit/cat_building_pittower_a_01_d.dds \
    Media/Models/Circuit/cat_building_pitgarages_a_06_d.dds \
    Media/Models/Circuit/cat_building_pitgarages_a_05_d.dds \
    Media/Models/Circuit/cat_building_pitgarages_a_04_d.dds \
    Media/Models/Circuit/cat_building_pitgarages_a_03_d.dds \
    Media/Models/Circuit/cat_building_pitgarages_a_02_d.dds \
    Media/Models/Circuit/cat_building_pitgarages_a_01_d.dds \
    Media/Models/Circuit/cat_building_partyhouse_a_01_d.dds \
    Media/Models/Circuit/cat_bridge_west_a_01_d.dds \
    Media/Models/Circuit/cat_bridge_startfinish_a_01_d.dds \
    Media/Models/Circuit/cat_bridge_junction_a_01_d.dds \
    Media/Models/Circuit/cat_barrier_redtarp_a_01_d.dds \
    Media/Models/Circuit/cat_barrier_paddockfrontgate_a_01_d.dds \
    Media/Models/Circuit/cat_barrier_paddockbacgate_a_01_d.dds \
    Media/Models/Circuit/cat_banner_longframe_a_01_d.dds \
    Media/Models/Circuit/cat_banner_greenframe_a_01_d.dds \
    Media/Models/Circuit/camera_scaffold_a_01_d.dds \
    Media/Models/Circuit/brake_white_150_a.dds \
    Media/Models/Circuit/brake_white_100_a.dds \
    Media/Models/Circuit/brake_white_50_a.dds \
    Media/Models/Circuit/brake_drs_a.dds \
    Media/Models/Circuit/brake_black_blank_a.dds \
    Media/Models/Circuit/banner_crowdpartition_a_01_d.dds \
    Media/Models/Circuit/armco_grey_main_a_01_d.dds \
    Media/Models/Circuit/allianz_decal_a.dds \
    Media/Models/Circuit/allianz_brake_a.dds \
    Media/Models/Circuit/advert_side_a_d.dds

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += assimp

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += IL
