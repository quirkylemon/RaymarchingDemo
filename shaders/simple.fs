#version 460 core

in vec2 fragCoord;
in float time;
out vec4 FragColor;

vec3 palette(float t) {
    return .5+.6*cos(5.28318*(t+vec3(.3,.416,.557)));
}

float sdBoxFrame( vec3 p, vec3 b, float e )
{
    p = abs(p)-b;
    vec3 q = abs(p+e)-e;

    return min(min(
        length(max(vec3(p.x,q.y,q.z),0.0))+min(max(p.x,max(q.y,q.z)),0.0),
        length(max(vec3(q.x,p.y,q.z),0.0))+min(max(q.x,max(p.y,q.z)),0.0)),
        length(max(vec3(q.x,q.y,p.z),0.0))+min(max(q.x,max(q.y,p.z)),0.0));
}

float sdSphere(vec3 p, float s) {
    return length(p) - s;
}

float opSmoothUnion(float distance1, float distance2, float mixAmount) {
    float h = clamp( 0.5 + 0.5 * (distance2 - distance1) / mixAmount, 0.0, 1.0 );
    return mix( distance2, distance1, h ) - mixAmount * h * (1.0 - h);
}

float map(vec3 p) {
    
    float d = 1;

    // Space repetition
    vec3 boxPos = vec3(0,0,0);
    
    d = min(d,sdBoxFrame(p + boxPos, vec3(1), 0.1 ));

    vec3 spherePos = vec3(0,0,0);
    

    float sphereSize = 0.1 + 1 * ((sin(time)+2)/2);

    d = min(d,sdSphere(p + spherePos, sphereSize));

    return opSmoothUnion(sdBoxFrame(p + boxPos, vec3(1), 0.1 ), sdSphere(p + spherePos, sphereSize), 1);
}

void main() {

    vec3 rayOrigin = vec3(0, 0, -3);
    vec3 rayDirection = vec3(normalize(vec3(fragCoord.xy, 1)));
    vec3 color = vec3(0);

    float totalDistance = 0;

    int i = 0;

    for (i = 0; i < 80; i++) {
        vec3 position = rayOrigin + rayDirection * totalDistance;

        float currentDistance = map(position);
        totalDistance += currentDistance;

        if (currentDistance < 0.001 || currentDistance > 100) break;
    }
    vec3 col = palette(totalDistance * 0.04 + float(i) * 0.005);
    vec3 col_g = vec3(totalDistance * 0.04 + float(i) * 0.005);
    FragColor = vec4(col_g, 1.0f);
}

