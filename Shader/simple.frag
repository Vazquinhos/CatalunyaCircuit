varying vec3 V;
varying vec3 L;
varying vec3 N;
varying vec2 texCoord;
uniform sampler2D texture;

void main()
{
    vec4 sum;
    vec4 amb;
    vec4 diff;
    vec4 spec;
    vec4 base = texture2D(texture, texCoord);

    vec3 R = normalize(-reflect(L,N));
    amb = (gl_FrontLightModelProduct.sceneColor * gl_FrontMaterial.ambient) +
    (gl_LightSource[0].ambient * gl_FrontMaterial.ambient);

    diff = gl_FrontLightProduct[0].diffuse * gl_FrontMaterial.diffuse * max(dot(N,L), 0.0);

    spec = gl_LightSource[0].specular * pow(max(dot(R,V), 0.0), gl_FrontMaterial.shininess);

    //gl_FragColor = amb;
    //gl_FragColor = diff;
    //gl_FragColor = spec;
    //gl_FragColor = base;
    //gl_FragColor = amb*base;
    //gl_FragColor = diff*base;
    //gl_FragColor = amb*base + diff*base;
    gl_FragColor = (amb*base + diff*base) + spec;
}
