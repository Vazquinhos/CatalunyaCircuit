#include "meshInstance.h"


/*-------------------------------------------------------------------
|  Function MeshInstance
|  Purpose: Creator. Default constructor
*-------------------------------------------------------------------*/
MeshInstance::MeshInstance()
{
}

/*-------------------------------------------------------------------
|  Function MeshInstance
|  Purpose: Creator. Default constructor
|  Parameters:  Point3D * minVertex:    Min vertex of the MeshInstance
|               Point3D *maxVertex:     Max vertex of the MeshInstance
|               Point3D *center:        Center vertex of the MeshInstance
|               GLuint displayListId    Display list of the MeshInstance
*-------------------------------------------------------------------*/
MeshInstance::MeshInstance(Point3D * minVertex, Point3D *maxVertex, Point3D *center, GLuint displayListId){
    this->_p_minVertex = minVertex;
    this->_p_maxVertex = maxVertex;
    this->_p_center = center;
    this->_gi_displayListId = displayListId;
}

/*-------------------------------------------------------------------
|  Function getMinVertex
|  Purpose: Getter
|  Returns: The min vertex of the MeshInstance
*-------------------------------------------------------------------*/
Point3D* MeshInstance::getMinVertex(){
    return _p_minVertex;
}

/*-------------------------------------------------------------------
|  Function getMaxVertex
|  Purpose: Getter
|  Returns: The max vertex of the MeshInstance
*-------------------------------------------------------------------*/
Point3D* MeshInstance::getMaxVertex(){
    return _p_maxVertex;
}

/*-------------------------------------------------------------------
|  Function getCenter
|  Purpose: Getter
|  Returns: The center vertex of the MeshInstance
*-------------------------------------------------------------------*/
Point3D* MeshInstance::getCenter(){
    return _p_center;
}

/*-------------------------------------------------------------------
|  Function getDisplayList
|  Purpose: Getter
|  Returns: The display list of the MeshInstance
*-------------------------------------------------------------------*/
GLuint MeshInstance::getDisplayList(){
    return _gi_displayListId;
}
