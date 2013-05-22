varying vec3 V;
varying vec3 L;
varying vec3 N;
varying vec2 texCoord;
uniform sampler2D texture;

void main()
{
    vec3 vertexPos = vec3(gl_ModelViewMatrix * gl_Vertex);
    V = -normalize(vertexPos);

    vec4 coord = vec4(gl_LightSource[0].position.xyz, 1.0);
    L = normalize(coord.xyz - vertexPos);

    N = (gl_NormalMatrix * gl_Normal);
    gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

    //gl_Position = ftransform();
    texCoord = gl_MultiTexCoord0.xy;
}
