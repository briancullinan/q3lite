/*

*/

#ifndef TR_POSTPROCESS_H
#define TR_POSTPROCESS_H

#include "tr_fbo.h"

void RB_ToneMap(FBO_t *hdrFbo, ivec4_t hdrBox, FBO_t *ldrFbo, ivec4_t ldrBox, int autoExposure);
void RB_BokehBlur(FBO_t *src, ivec4_t srcBox, FBO_t *dst, ivec4_t dstBox, float blur);
void RB_SunRays(FBO_t *srcFbo, ivec4_t srcBox, FBO_t *dstFbo, ivec4_t dstBox);
void RB_GaussianBlur(float blur);

#endif
