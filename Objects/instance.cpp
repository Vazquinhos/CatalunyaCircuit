#include "instance.h"


/*-------------------------------------------------------------------
|  Function Instance
|  Purpose: Creator. Default constructor
*-------------------------------------------------------------------*/
Instance::Instance()
{
}

/*-------------------------------------------------------------------
|  Function Instance
|  Purpose: Creator. Default constructor
|  Parameters:  Point3D * minVertex:    Min vertex of the instance
|               Point3D *maxVertex:     Max vertex of the instance
|               Point3D *center:        Center vertex of the instance
|               GLuint displayListId    Display list of the instance
*-------------------------------------------------------------------*/
Instance::Instance(Point3D * minVertex, Point3D *maxVertex, Point3D *center, GLuint displayListId){
    this->_p_minVertex = minVertex;
    this->_p_maxVertex = maxVertex;
    this->_p_center = center;
    this->_gi_displayListId = displayListId;
}

/*-------------------------------------------------------------------
|  Function getMinVertex
|  Purpose: Getter
|  Returns: The min vertex of the instance
*-------------------------------------------------------------------*/
Point3D* Instance::getMinVertex(){
    return _p_minVertex;
}

/*-------------------------------------------------------------------
|  Function getMaxVertex
|  Purpose: Getter
|  Returns: The max vertex of the instance
*-------------------------------------------------------------------*/
Point3D* Instance::getMaxVertex(){
    return _p_maxVertex;
}

/*-------------------------------------------------------------------
|  Function getCenter
|  Purpose: Getter
|  Returns: The center vertex of the instance
*-------------------------------------------------------------------*/
Point3D* Instance::getCenter(){
    return _p_center;
}

/*-------------------------------------------------------------------
|  Function getDisplayList
|  Purpose: Getter
|  Returns: The display list of the instance
*-------------------------------------------------------------------*/
GLuint Instance::getDisplayList(){
    return _gi_displayListId;
}
