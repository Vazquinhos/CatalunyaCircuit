/*
 * Archivo: enviroment.cpp
 * Fecha: 19/03/2013
 * Autores: David Pérez Castilla
 *          Alejandro Vázquez
 *          Fernando Perera
 *          Darío Orgaz Manjón
 *          Gabriel Diaz Arias
 */

#include "enviroment.h"
#include "Objects/modelManager.h"
#include <QDir>
#include <QString>

// ================= Constructores/Destructores ======================

/*-------------------------------------------------------------------
 |  Default Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment()
{

   ModelManager *manager = ModelManager::getModelManager();
   _terrain3D = manager->getModel("terrain.3ds");
   _sky3D = manager->getModel("sky.3ds");

   _banderas_13D = manager->getModel("banderas_1.3ds");
   _banderas_23D = manager->getModel("banderas_2.3ds");
   _banderas_33D = manager->getModel("banderas_3.3ds");
   _banderas_43D = manager->getModel("banderas_4.3ds");
   _banderas_53D = manager->getModel("banderas_5.3ds");
   _banderas_63D = manager->getModel("banderas_6.3ds");
   _banderas_73D = manager->getModel("banderas_7.3ds");
   _banderas_83D = manager->getModel("banderas_8.3ds");
   _banderas_93D = manager->getModel("banderas_9.3ds");
   _banderas_103D = manager->getModel("banderas_10.3ds");
   _banderas_113D = manager->getModel("banderas_11.3ds");
   _banderas_123D = manager->getModel("banderas_12.3ds");
   _banderas_133D = manager->getModel("banderas_13.3ds");
   _banderas_143D = manager->getModel("banderas_14.3ds");
   _banderas_153D = manager->getModel("banderas_15.3ds");
   _banderas_163D = manager->getModel("banderas_16.3ds");
   _banderas_173D = manager->getModel("banderas_17.3ds");

   _barreras_13D = manager->getModel("barreras_1.3ds");
   _barreras_23D = manager->getModel("barreras_2.3ds");
   _barreras_33D = manager->getModel("barreras_3.3ds");
   _barreras_43D = manager->getModel("barreras_4.3ds");
   _barreras_53D = manager->getModel("barreras_5.3ds");
   _barreras_63D = manager->getModel("barreras_6.3ds");
   _barreras_73D = manager->getModel("barreras_7.3ds");
   _barreras_83D = manager->getModel("barreras_8.3ds");
   _barreras_93D = manager->getModel("barreras_9.3ds");
   _barreras_103D = manager->getModel("barreras_10.3ds");
   _barreras_113D = manager->getModel("barreras_11.3ds");
   _barreras_123D = manager->getModel("barreras_12.3ds");
   _barreras_133D = manager->getModel("barreras_13.3ds");
   _barreras_143D = manager->getModel("barreras_14.3ds");
   _barreras_153D = manager->getModel("barreras_15.3ds");

   _buildings1_13D = manager->getModel("buildings1_1.3ds");
   _buildings1_23D = manager->getModel("buildings1_2.3ds");
   _buildings1_33D = manager->getModel("buildings1_3.3ds");
   _buildings1_43D = manager->getModel("buildings1_4.3ds");
   _buildings1_53D = manager->getModel("buildings1_5.3ds");
   _buildings1_63D = manager->getModel("buildings1_6.3ds");
   _buildings1_73D = manager->getModel("buildings1_7.3ds");
   _buildings1_83D = manager->getModel("buildings1_8.3ds");
   _buildings1_93D = manager->getModel("buildings1_9.3ds");
   _buildings1_103D = manager->getModel("buildings1_10.3ds");
   _buildings1_113D = manager->getModel("buildings1_11.3ds");
   _buildings1_123D = manager->getModel("buildings1_12.3ds");

   _buildings2_13D = manager->getModel("buildings2_1.3ds");
   _buildings2_23D = manager->getModel("buildings2_2.3ds");
   _buildings2_33D = manager->getModel("buildings2_3.3ds");
   _buildings2_43D = manager->getModel("buildings2_4.3ds");

   _buildings3_13D = manager->getModel("buildings3_1.3ds");
   _buildings3_23D = manager->getModel("buildings3_2.3ds");
   _buildings3_33D = manager->getModel("buildings3_3.3ds");
   _buildings3_53D = manager->getModel("buildings3_5.3ds");
   _buildings3_63D = manager->getModel("buildings3_6.3ds");

   _buildings4_13D = manager->getModel("buildings4_1.3ds");
   _buildings4_23D = manager->getModel("buildings4_2.3ds");

   _objects_13D = manager->getModel("objects_1.3ds");
   _objects_23D = manager->getModel("objects_2.3ds");
   _objects_33D = manager->getModel("objects_3.3ds");
   _objects_43D = manager->getModel("objects_4.3ds");
   _objects_53D = manager->getModel("objects_5.3ds");
   _objects_63D = manager->getModel("objects_6.3ds");
   _objects_73D = manager->getModel("objects_7.3ds");
   _objects_83D = manager->getModel("objects_8.3ds");
   _objects_93D = manager->getModel("objects_9.3ds");
   _objects_103D = manager->getModel("objects_10.3ds");
   _objects_113D = manager->getModel("objects_11.3ds");
   _objects_123D = manager->getModel("objects_12.3ds");
   _objects_133D = manager->getModel("objects_13.3ds");
   _objects_143D = manager->getModel("objects_14.3ds");
   _objects_153D = manager->getModel("objects_15.3ds");
   _objects_163D = manager->getModel("objects_16.3ds");
   _objects_173D = manager->getModel("objects_17.3ds");
   _objects_183D = manager->getModel("objects_18.3ds");
   _objects_193D = manager->getModel("objects_19.3ds");
   _objects_203D = manager->getModel("objects_20.3ds");


   _vallas_13D = manager->getModel("vallas_1.3ds");
   _vallas_23D = manager->getModel("vallas_2.3ds");
   _vallas_33D = manager->getModel("vallas_3.3ds");
   _vallas_43D = manager->getModel("vallas_4.3ds");
   _vallas_53D = manager->getModel("vallas_5.3ds");
   _vallas_63D = manager->getModel("vallas_6.3ds");
   _vallas_73D = manager->getModel("vallas_7.3ds");
   _vallas_83D = manager->getModel("vallas_8.3ds");
   _vallas_93D = manager->getModel("vallas_9.3ds");
   _vallas_103D = manager->getModel("vallas_10.3ds");
   _vallas_113D = manager->getModel("vallas_11.3ds");
   _vallas_123D = manager->getModel("vallas_12.3ds");
   _vallas_133D = manager->getModel("vallas_13.3ds");
   _vallas_143D = manager->getModel("vallas_14.3ds");
   _vallas_153D = manager->getModel("vallas_15.3ds");
   _vallas_163D = manager->getModel("vallas_16.3ds");
   _vallas_173D = manager->getModel("vallas_17.3ds");
   _vallas_183D = manager->getModel("vallas_18.3ds");
   _vallas_193D = manager->getModel("vallas_19.3ds");
   _vallas_203D = manager->getModel("vallas_20.3ds");
   _vallas_213D = manager->getModel("vallas_21.3ds");
   _vallas_223D = manager->getModel("vallas_22.3ds");
   _vallas_233D = manager->getModel("vallas_23.3ds");
   _vallas_243D = manager->getModel("vallas_24.3ds");
   _vallas_253D = manager->getModel("vallas_25.3ds");
   _vallas_263D = manager->getModel("vallas_26.3ds");
   _vallas_273D = manager->getModel("vallas_27.3ds");
   _vallas_283D = manager->getModel("vallas_28.3ds");

   _vegetacion_13D = manager->getModel("vegetacion_1.3ds");
   _vegetacion_23D = manager->getModel("vegetacion_2.3ds");
   _vegetacion_33D = manager->getModel("vegetacion_3.3ds");
   _vegetacion_43D = manager->getModel("vegetacion_4.3ds");
   _vegetacion_53D = manager->getModel("vegetacion_5.3ds");
   _vegetacion_63D = manager->getModel("vegetacion_6.3ds");
   _vegetacion_73D = manager->getModel("vegetacion_7.3ds");
   _vegetacion_83D = manager->getModel("vegetacion_8.3ds");
   _vegetacion_93D = manager->getModel("vegetacion_9.3ds");
   _vegetacion_103D = manager->getModel("vegetacion_10.3ds");
   _vegetacion_113D = manager->getModel("vegetacion_11.3ds");
   _vegetacion_123D = manager->getModel("vegetacion_12.3ds");
   _vegetacion_133D = manager->getModel("vegetacion_13.3ds");
   _vegetacion_143D = manager->getModel("vegetacion_14.3ds");
   _vegetacion_153D = manager->getModel("vegetacion_15.3ds");
   _vegetacion_163D = manager->getModel("vegetacion_16.3ds");
   _vegetacion_173D = manager->getModel("vegetacion_17.3ds");
   _vegetacion_183D = manager->getModel("vegetacion_18.3ds");
   _vegetacion_193D = manager->getModel("vegetacion_19.3ds");
   _vegetacion_203D = manager->getModel("vegetacion_20.3ds");
   _vegetacion_213D = manager->getModel("vegetacion_21.3ds");
   _vegetacion_223D = manager->getModel("vegetacion_22.3ds");
   _vegetacion_233D = manager->getModel("vegetacion_23.3ds");
   _vegetacion_243D = manager->getModel("vegetacion_24.3ds");
   _vegetacion_253D = manager->getModel("vegetacion_25.3ds");

   _vallasPlastico_13D = manager->getModel("vallasPlastico_1.3ds");
   _vallasPlastico_23D = manager->getModel("vallasPlastico_2.3ds");
   _vallasPlastico_33D = manager->getModel("vallasPlastico_3.3ds");
   _vallasPlastico_43D = manager->getModel("vallasPlastico_4.3ds");
   _vallasPlastico_53D = manager->getModel("vallasPlastico_5.3ds");
   _vallasPlastico_63D = manager->getModel("vallasPlastico_6.3ds");
   _vallasPlastico_73D = manager->getModel("vallasPlastico_7.3ds");
   _vallasPlastico_83D = manager->getModel("vallasPlastico_8.3ds");
   _vallasPlastico_93D = manager->getModel("vallasPlastico_9.3ds");
   _vallasPlastico_103D = manager->getModel("vallasPlastico_10.3ds");
   _vallasPlastico_113D = manager->getModel("vallasPlastico_11.3ds");
   _vallasPlastico_123D = manager->getModel("vallasPlastico_12.3ds");
   _vallasPlastico_133D = manager->getModel("vallasPlastico_13.3ds");
   _vallasPlastico_143D = manager->getModel("vallasPlastico_14.3ds");
   _vallasPlastico_153D = manager->getModel("vallasPlastico_15.3ds");
   _vallasPlastico_163D = manager->getModel("vallasPlastico_16.3ds");
   _vallasPlastico_173D = manager->getModel("vallasPlastico_17.3ds");
   _vallasPlastico_183D = manager->getModel("vallasPlastico_18.3ds");
   _vallasPlastico_193D = manager->getModel("vallasPlastico_19.3ds");
   _vallasPlastico_203D = manager->getModel("vallasPlastico_20.3ds");
   _vallasPlastico_223D = manager->getModel("vallasPlastico_21.3ds");
   _vallasPlastico_213D = manager->getModel("vallasPlastico_22.3ds");
   _vallasPlastico_233D = manager->getModel("vallasPlastico_23.3ds");
   _vallasPlastico_243D = manager->getModel("vallasPlastico_24.3ds");
   _vallasPlastico_253D = manager->getModel("vallasPlastico_25.3ds");
   _vallasPlastico_263D = manager->getModel("vallasPlastico_26.3ds");
   _vallasPlastico_273D = manager->getModel("vallasPlastico_27.3ds");
   _vallasPlastico_283D = manager->getModel("vallasPlastico_28.3ds");
   _vallasPlastico_293D = manager->getModel("vallasPlastico_29.3ds");
   _vallasPlastico_303D = manager->getModel("vallasPlastico_30.3ds");
   _vallasPlastico_313D = manager->getModel("vallasPlastico_31.3ds");
   _vallasPlastico_323D = manager->getModel("vallasPlastico_32.3ds");
   _vallasPlastico_333D = manager->getModel("vallasPlastico_33.3ds");
   _vallasPlastico_343D = manager->getModel("vallasPlastico_34.3ds");
   _vallasPlastico_353D = manager->getModel("vallasPlastico_35.3ds");
   _vallasPlastico_363D = manager->getModel("vallasPlastico_36.3ds");
   _vallasPlastico_373D = manager->getModel("vallasPlastico_37.3ds");
   _vallasPlastico_383D = manager->getModel("vallasPlastico_38.3ds");
   _vallasPlastico_393D = manager->getModel("vallasPlastico_39.3ds");
   _vallasPlastico_403D = manager->getModel("vallasPlastico_40.3ds");

}

/*-------------------------------------------------------------------
 |  Copy Constructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::Enviroment(const Enviroment &enviroment)
{
}

/*-------------------------------------------------------------------
 |  Destructor
 |
 |  Purpose:
 |  Parameters:
 |  Returns:
 *-------------------------------------------------------------------*/
Enviroment::~Enviroment()
{
}

// ============================ Methods ===============================


// ============================ Inherited Methods ===============================
/*-------------------------------------------------------------------
 |  Function displayModels
 |
 |  Purpose: Displays all models
 *-------------------------------------------------------------------*/
void Enviroment::displayModels(){

    _terrain3D->display();
    _sky3D->display();

    _banderas_13D->display();
    _banderas_23D->display();
    _banderas_33D->display();
    _banderas_43D->display();
    _banderas_53D->display();
    _banderas_63D->display();
    _banderas_73D->display();
    _banderas_83D->display();
    _banderas_93D->display();
    _banderas_103D->display();
    _banderas_113D->display();
    _banderas_123D->display();
    _banderas_133D->display();
    _banderas_143D->display();
    _banderas_153D->display();
    _banderas_163D->display();
    _banderas_173D->display();

    _barreras_13D->display();
    _barreras_23D->display();
    _barreras_33D->display();
    _barreras_43D->display();
    _barreras_53D->display();
    _barreras_63D->display();
    _barreras_73D->display();
    _barreras_83D->display();
    _barreras_93D->display();
    _barreras_103D->display();
    _barreras_113D->display();
    _barreras_123D->display();
    _barreras_133D->display();
    _barreras_143D->display();
    _barreras_153D->display();

    _buildings1_13D->display();
    _buildings1_23D->display();
    _buildings1_33D->display();
    _buildings1_43D->display();
    _buildings1_53D->display();
    _buildings1_63D->display();
    _buildings1_73D->display();
    _buildings1_83D->display();
    _buildings1_93D->display();
    _buildings1_103D->display();
    _buildings1_113D->display();
    _buildings1_123D->display();

    _buildings2_13D->display();
    _buildings2_23D->display();
    _buildings2_33D->display();
    _buildings2_43D->display();

    _buildings3_13D->display();
    _buildings3_23D->display();
    _buildings3_33D->display();
    _buildings3_53D->display();
    _buildings3_63D->display();

    _buildings4_13D->display();
    _buildings4_23D->display();

    _objects_13D->display();
    _objects_23D->display();
    _objects_33D->display();
    _objects_43D->display();
    _objects_53D->display();
    _objects_63D->display();
    _objects_73D->display();
    _objects_83D->display();
    _objects_93D->display();
    _objects_103D->display();
    _objects_113D->display();
    _objects_123D->display();
    _objects_133D->display();
    _objects_143D->display();
    _objects_153D->display();
    _objects_163D->display();
    _objects_173D->display();
    _objects_183D->display();
    _objects_193D->display();
    _objects_203D->display();


    _vallas_13D->display();
    _vallas_23D->display();
    _vallas_33D->display();
    _vallas_43D->display();
    _vallas_53D->display();
    _vallas_63D->display();
    _vallas_73D->display();
    _vallas_83D->display();
    _vallas_93D->display();
    _vallas_103D->display();
    _vallas_113D->display();
    _vallas_123D->display();
    _vallas_133D->display();
    _vallas_143D->display();
    _vallas_153D->display();
    _vallas_163D->display();
    _vallas_173D->display();
    _vallas_183D->display();
    _vallas_193D->display();
    _vallas_203D->display();
    _vallas_213D->display();
    _vallas_223D->display();
    _vallas_233D->display();
    _vallas_243D->display();
    _vallas_253D->display();
    _vallas_263D->display();
    _vallas_273D->display();
    _vallas_283D->display();

    _vegetacion_13D->display();
    _vegetacion_23D->display();
    _vegetacion_33D->display();
    _vegetacion_43D->display();
    _vegetacion_53D->display();
    _vegetacion_63D->display();
    _vegetacion_73D->display();
    _vegetacion_83D->display();
    _vegetacion_93D->display();
    _vegetacion_103D->display();
    _vegetacion_113D->display();
    _vegetacion_123D->display();
    _vegetacion_133D->display();
    _vegetacion_143D->display();
    _vegetacion_153D->display();
    _vegetacion_163D->display();
    _vegetacion_173D->display();
    _vegetacion_183D->display();
    _vegetacion_193D->display();
    _vegetacion_203D->display();
    _vegetacion_213D->display();
    _vegetacion_223D->display();
    _vegetacion_233D->display();
    _vegetacion_243D->display();
    _vegetacion_253D->display();

    _vallasPlastico_13D->display();
    _vallasPlastico_23D->display();
    _vallasPlastico_33D->display();
    _vallasPlastico_43D->display();
    _vallasPlastico_53D->display();
    _vallasPlastico_63D->display();
    _vallasPlastico_73D->display();
    _vallasPlastico_83D->display();
    _vallasPlastico_93D->display();
    _vallasPlastico_103D->display();
    _vallasPlastico_113D->display();
    _vallasPlastico_123D->display();
    _vallasPlastico_133D->display();
    _vallasPlastico_143D->display();
    _vallasPlastico_153D->display();
    _vallasPlastico_163D->display();
    _vallasPlastico_173D->display();
    _vallasPlastico_183D->display();
    _vallasPlastico_193D->display();
    _vallasPlastico_203D->display();
    _vallasPlastico_223D->display();
    _vallasPlastico_213D->display();
    _vallasPlastico_233D->display();
    _vallasPlastico_243D->display();
    _vallasPlastico_253D->display();
    _vallasPlastico_263D->display();
    _vallasPlastico_273D->display();
    _vallasPlastico_283D->display();
    _vallasPlastico_293D->display();
    _vallasPlastico_303D->display();
    _vallasPlastico_313D->display();
    _vallasPlastico_323D->display();
    _vallasPlastico_333D->display();
    _vallasPlastico_343D->display();
    _vallasPlastico_353D->display();
    _vallasPlastico_363D->display();
    _vallasPlastico_373D->display();
    _vallasPlastico_383D->display();
    _vallasPlastico_393D->display();
    _vallasPlastico_403D->display();

}

/*-------------------------------------------------------------------
 |  Function checkVisibility
 |
 |  Purpose: Modify visibility of the objects taking in consideration distance to the camera
 |  Parameters: Point3D *pointCamera : Position of the camera, int distance : Maximum distance that the object will be visible
 *-------------------------------------------------------------------*/
void Enviroment::checkVisibility(Point3D *pointCamera, int distance){
     _terrain3D->checkVisibility(pointCamera, distance);

    _banderas_13D->checkVisibility(pointCamera, distance);
    _banderas_23D->checkVisibility(pointCamera, distance);
    _banderas_33D->checkVisibility(pointCamera, distance);
    _banderas_43D->checkVisibility(pointCamera, distance);
    _banderas_53D->checkVisibility(pointCamera, distance);
    _banderas_63D->checkVisibility(pointCamera, distance);
    _banderas_73D->checkVisibility(pointCamera, distance);
    _banderas_83D->checkVisibility(pointCamera, distance);
    _banderas_93D->checkVisibility(pointCamera, distance);
    _banderas_103D->checkVisibility(pointCamera, distance);
    _banderas_113D->checkVisibility(pointCamera, distance);
    _banderas_123D->checkVisibility(pointCamera, distance);
    _banderas_133D->checkVisibility(pointCamera, distance);
    _banderas_143D->checkVisibility(pointCamera, distance);
    _banderas_153D->checkVisibility(pointCamera, distance);
    _banderas_163D->checkVisibility(pointCamera, distance);
    _banderas_173D->checkVisibility(pointCamera, distance);

    _barreras_13D->checkVisibility(pointCamera, distance);
    _barreras_23D->checkVisibility(pointCamera, distance);
    _barreras_33D->checkVisibility(pointCamera, distance);
    _barreras_43D->checkVisibility(pointCamera, distance);
    _barreras_53D->checkVisibility(pointCamera, distance);
    _barreras_63D->checkVisibility(pointCamera, distance);
    _barreras_73D->checkVisibility(pointCamera, distance);
    _barreras_83D->checkVisibility(pointCamera, distance);
    _barreras_93D->checkVisibility(pointCamera, distance);
    _barreras_103D->checkVisibility(pointCamera, distance);
    _barreras_113D->checkVisibility(pointCamera, distance);
    _barreras_123D->checkVisibility(pointCamera, distance);
    _barreras_133D->checkVisibility(pointCamera, distance);
    _barreras_143D->checkVisibility(pointCamera, distance);
    _barreras_153D->checkVisibility(pointCamera, distance);

    _buildings1_13D->checkVisibility(pointCamera, distance);
    _buildings1_23D->checkVisibility(pointCamera, distance);
    _buildings1_33D->checkVisibility(pointCamera, distance);
    _buildings1_43D->checkVisibility(pointCamera, distance);
    _buildings1_53D->checkVisibility(pointCamera, distance);
    _buildings1_63D->checkVisibility(pointCamera, distance);
    _buildings1_73D->checkVisibility(pointCamera, distance);
    _buildings1_83D->checkVisibility(pointCamera, distance);
    _buildings1_93D->checkVisibility(pointCamera, distance);
    _buildings1_103D->checkVisibility(pointCamera, distance);
    _buildings1_113D->checkVisibility(pointCamera, distance);
    _buildings1_123D->checkVisibility(pointCamera, distance);

    _buildings2_13D->checkVisibility(pointCamera, distance);
    _buildings2_23D->checkVisibility(pointCamera, distance);
    _buildings2_33D->checkVisibility(pointCamera, distance);
    _buildings2_43D->checkVisibility(pointCamera, distance);

    _buildings3_13D->checkVisibility(pointCamera, distance);
    _buildings3_23D->checkVisibility(pointCamera, distance);
    _buildings3_33D->checkVisibility(pointCamera, distance);
    _buildings3_53D->checkVisibility(pointCamera, distance);
    _buildings3_63D->checkVisibility(pointCamera, distance);

    _buildings4_13D->checkVisibility(pointCamera, distance);
    _buildings4_23D->checkVisibility(pointCamera, distance);


    _objects_13D->checkVisibility(pointCamera, distance);
    _objects_23D->checkVisibility(pointCamera, distance);
    _objects_33D->checkVisibility(pointCamera, distance);
    _objects_43D->checkVisibility(pointCamera, distance);
    _objects_53D->checkVisibility(pointCamera, distance);
    _objects_63D->checkVisibility(pointCamera, distance);
    _objects_73D->checkVisibility(pointCamera, distance);
    _objects_83D->checkVisibility(pointCamera, distance);
    _objects_93D->checkVisibility(pointCamera, distance);
    _objects_103D->checkVisibility(pointCamera, distance);
    _objects_113D->checkVisibility(pointCamera, distance);
    _objects_123D->checkVisibility(pointCamera, distance);
    _objects_133D->checkVisibility(pointCamera, distance);
    _objects_143D->checkVisibility(pointCamera, distance);
    _objects_153D->checkVisibility(pointCamera, distance);
    _objects_163D->checkVisibility(pointCamera, distance);
    _objects_173D->checkVisibility(pointCamera, distance);
    _objects_183D->checkVisibility(pointCamera, distance);
    _objects_193D->checkVisibility(pointCamera, distance);
    _objects_203D->checkVisibility(pointCamera, distance);


    _vallas_13D->checkVisibility(pointCamera, distance);
    _vallas_23D->checkVisibility(pointCamera, distance);
    _vallas_33D->checkVisibility(pointCamera, distance);
    _vallas_43D->checkVisibility(pointCamera, distance);
    _vallas_53D->checkVisibility(pointCamera, distance);
    _vallas_63D->checkVisibility(pointCamera, distance);
    _vallas_73D->checkVisibility(pointCamera, distance);
    _vallas_83D->checkVisibility(pointCamera, distance);
    _vallas_93D->checkVisibility(pointCamera, distance);
    _vallas_103D->checkVisibility(pointCamera, distance);
    _vallas_113D->checkVisibility(pointCamera, distance);
    _vallas_123D->checkVisibility(pointCamera, distance);
    _vallas_133D->checkVisibility(pointCamera, distance);
    _vallas_143D->checkVisibility(pointCamera, distance);
    _vallas_153D->checkVisibility(pointCamera, distance);
    _vallas_163D->checkVisibility(pointCamera, distance);
    _vallas_173D->checkVisibility(pointCamera, distance);
    _vallas_183D->checkVisibility(pointCamera, distance);
    _vallas_193D->checkVisibility(pointCamera, distance);
    _vallas_203D->checkVisibility(pointCamera, distance);
    _vallas_213D->checkVisibility(pointCamera, distance);
    _vallas_223D->checkVisibility(pointCamera, distance);
    _vallas_233D->checkVisibility(pointCamera, distance);
    _vallas_243D->checkVisibility(pointCamera, distance);
    _vallas_253D->checkVisibility(pointCamera, distance);
    _vallas_263D->checkVisibility(pointCamera, distance);
    _vallas_273D->checkVisibility(pointCamera, distance);
    _vallas_283D->checkVisibility(pointCamera, distance);

    _vegetacion_13D->checkVisibility(pointCamera, distance);
    _vegetacion_23D->checkVisibility(pointCamera, distance);
    _vegetacion_33D->checkVisibility(pointCamera, distance);
    _vegetacion_43D->checkVisibility(pointCamera, distance);
    _vegetacion_53D->checkVisibility(pointCamera, distance);
    _vegetacion_63D->checkVisibility(pointCamera, distance);
    _vegetacion_73D->checkVisibility(pointCamera, distance);
    _vegetacion_83D->checkVisibility(pointCamera, distance);
    _vegetacion_93D->checkVisibility(pointCamera, distance);
    _vegetacion_103D->checkVisibility(pointCamera, distance);
    _vegetacion_113D->checkVisibility(pointCamera, distance);
    _vegetacion_123D->checkVisibility(pointCamera, distance);
    _vegetacion_133D->checkVisibility(pointCamera, distance);
    _vegetacion_143D->checkVisibility(pointCamera, distance);
    _vegetacion_153D->checkVisibility(pointCamera, distance);
    _vegetacion_163D->checkVisibility(pointCamera, distance);
    _vegetacion_173D->checkVisibility(pointCamera, distance);
    _vegetacion_183D->checkVisibility(pointCamera, distance);
    _vegetacion_193D->checkVisibility(pointCamera, distance);
    _vegetacion_203D->checkVisibility(pointCamera, distance);
    _vegetacion_213D->checkVisibility(pointCamera, distance);
    _vegetacion_223D->checkVisibility(pointCamera, distance);
    _vegetacion_233D->checkVisibility(pointCamera, distance);
    _vegetacion_243D->checkVisibility(pointCamera, distance);
    _vegetacion_253D->checkVisibility(pointCamera, distance);

    _vallasPlastico_13D->checkVisibility(pointCamera, distance);
    _vallasPlastico_23D->checkVisibility(pointCamera, distance);
    _vallasPlastico_33D->checkVisibility(pointCamera, distance);
    _vallasPlastico_43D->checkVisibility(pointCamera, distance);
    _vallasPlastico_53D->checkVisibility(pointCamera, distance);
    _vallasPlastico_63D->checkVisibility(pointCamera, distance);
    _vallasPlastico_73D->checkVisibility(pointCamera, distance);
    _vallasPlastico_83D->checkVisibility(pointCamera, distance);
    _vallasPlastico_93D->checkVisibility(pointCamera, distance);
    _vallasPlastico_103D->checkVisibility(pointCamera, distance);
    _vallasPlastico_113D->checkVisibility(pointCamera, distance);
    _vallasPlastico_123D->checkVisibility(pointCamera, distance);
    _vallasPlastico_133D->checkVisibility(pointCamera, distance);
    _vallasPlastico_143D->checkVisibility(pointCamera, distance);
    _vallasPlastico_153D->checkVisibility(pointCamera, distance);
    _vallasPlastico_163D->checkVisibility(pointCamera, distance);
    _vallasPlastico_173D->checkVisibility(pointCamera, distance);
    _vallasPlastico_183D->checkVisibility(pointCamera, distance);
    _vallasPlastico_193D->checkVisibility(pointCamera, distance);
    _vallasPlastico_203D->checkVisibility(pointCamera, distance);
    _vallasPlastico_223D->checkVisibility(pointCamera, distance);
    _vallasPlastico_213D->checkVisibility(pointCamera, distance);
    _vallasPlastico_233D->checkVisibility(pointCamera, distance);
    _vallasPlastico_243D->checkVisibility(pointCamera, distance);
    _vallasPlastico_253D->checkVisibility(pointCamera, distance);
    _vallasPlastico_263D->checkVisibility(pointCamera, distance);
    _vallasPlastico_273D->checkVisibility(pointCamera, distance);
    _vallasPlastico_283D->checkVisibility(pointCamera, distance);
    _vallasPlastico_293D->checkVisibility(pointCamera, distance);
    _vallasPlastico_303D->checkVisibility(pointCamera, distance);
    _vallasPlastico_313D->checkVisibility(pointCamera, distance);
    _vallasPlastico_323D->checkVisibility(pointCamera, distance);
    _vallasPlastico_333D->checkVisibility(pointCamera, distance);
    _vallasPlastico_343D->checkVisibility(pointCamera, distance);
    _vallasPlastico_353D->checkVisibility(pointCamera, distance);
    _vallasPlastico_363D->checkVisibility(pointCamera, distance);
    _vallasPlastico_373D->checkVisibility(pointCamera, distance);
    _vallasPlastico_383D->checkVisibility(pointCamera, distance);
    _vallasPlastico_393D->checkVisibility(pointCamera, distance);
    _vallasPlastico_403D->checkVisibility(pointCamera, distance);
}


