/*
Main  module of engine
we get information about  ceritain proccessor  
take defined power of it  
Video cart information 
Developed By 
Blessed soft company 2020
*/


#include <graphics.h> 
#include "map_creating.h"
#include "module_phs.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include "create_objects.c"


//all information preprocessor
struct Preprocessor_engine  
{
   // main data of  a proccessor 
  
  char name_of_proccessor_for_engine;
  int proccesor_speed;
 
  // if user will take so a lot speed  we will message to  him. 

  int get_proccessor_speed  ( int proccessor_speed )
  {  
    // we'll take computer proccessor speed   
    int needed_power_for_computer ;
    scanf("Enter neccessuary power of proccessor :", needed_power_for_computer );
    if (needed_power_for_computer >= proccessor_speed)
    {
        print("You can't  take  this  value of speed for work , sorry");
        int get_proccessor_speed ();
    }
    //save amount needed  memory  in array 
    void save_needed_power_for_computer()
    {
        int Memory_needed_power [50] = { needed_power_for_computer  };  
    }
    get_and_take_needed_speed_of_computer_and_use_it (int needed_power_for_computer);




    
    return needed_power_for_computer ;
  }


 // we render Image  with help some  matrixs. 
  void Rendering_Image()
{  
  // Create and initialize the rasterizer rendering context
RenderContext* pRenderContext = new RenderContext(config);
pRenderContext-&gt;Initialize()

  // Allocate color &amp; depth buffers
  uint8_t* pColorBuffer = ... // Color buffer format == R8G8B8A8_UNORM
   float* pDepthBuffer = ... // Depth buffer format == D32_FLOAT

  // Set up main FBO
  Framebuffer fbo = {};
   fbo.m_pColorBuffer = pColorBuffer;
  fbo.m_pDepthBuffer = pDepthBuffer;
   fbo.m_Width = opt.m_ScreenWidth;
  fbo.m_Height = opt.m_ScreenHeight;

  // Single vec3 attribute is used to pass vertex normal VS -&gt; FS
  ShaderMetadata metadata = { 0, 1 /*vertex normal*/, 0 };

  // Emulate passing of constants data to shaders
  Constants cb;
  cb.m_ModelViewProj = proj * view * model;

  // We will have single index and vertex buffer to draw indexed mesh
  std::vector<Vertex&gt; vertexBuffer;
  std::vector<uint32_t&gt; indexBuffer;
  // Store data of all scene objects to be drawn
  std::vector<Mesh&gt; objects;

  // Load .OBJ scene model data and generate vertex/index buffers, etc.
  InitializeSceneObjects(opt.m_OBJName, objects, vertexBuffer, indexBuffer);

  // Bind FBO to be used in subsequent render pass once
  pRenderContext-&gt;BindFramebuffer(&amp;fbo);

  // Bind VBO and set buffer stride
  pRenderContext-&gt;BindVertexBuffer(vertexBuffer.data(), sizeof(Vertex));
  // Bind IBO
  pRenderContext-&gt;BindIndexBuffer(indexBuffer.data());

  // Bind shader constants
  pRenderContext-&gt;BindConstantBuffer(&amp;cb);

   // Bind shader, constant buffer, texture(s)
   pRenderContext-&gt;BindShaders(VS, FS, metadata);

   // Clear RT
                pRenderContext-&gt;BeginRenderPass(
                    true, /*clearColor*/
                    glm::vec4(0, 0, 0, 1) /*colorValue*/,
                    true, /*clearDepth*/
                    FLT_MAX /*depthValue*/);

                // Draw meshes
                for (uint32_t obj = 0; obj < objects.size(); obj++)
                {
                    Mesh&amp; mesh = objects[obj];

                    view = glm::lookAt(testParams.m_EyePos, testParams.m_LookAtPos, glm::vec3(0, 1, 0));
                    //model = glm::rotate(model, glm::radians(0.5f), glm::vec3(0, 1, 0));
                    cb.m_ModelViewProj = proj * view * model;

                    // Kick off draw. Note that it blocks callee until drawcall is completed
                    pRenderContext-&gt;DrawIndexed(mesh.m_IdxCount, mesh.m_IdxOffset);
                }

                pRenderContext-&gt;EndRenderPass();


      // Prepare for next drawcall
ApplyPreDrawcallStateInvalidations();

uint32_t numRemainingPrims = primCount;

uint32_t drawElemsPrev = 0u;
uint32_t numIter = 0;

while (numRemainingPrims &gt; 0)
{
    // Prepare for next draw iteration
    ApplyPreDrawIterationStateInvalidations();

    // How many prims are to be processed this iteration &amp; prims per thread
    uint32_t iterationSize = (numRemainingPrims &gt;= m_RenderConfig.m_MaxDrawIterationSize) ? m_RenderConfig.m_MaxDrawIterationSize : numRemainingPrims;
    uint32_t perIterationRemainder = iterationSize % m_RenderConfig.m_NumPipelineThreads;
    uint32_t primsPerThread = iterationSize / m_RenderConfig.m_NumPipelineThreads;

    for (uint32_t threadIdx = 0; threadIdx < m_RenderConfig.m_NumPipelineThreads; threadIdx++)
    {
        uint32_t currentDrawElemsStart = drawElemsPrev;
        uint32_t currentDrawElemsEnd = (threadIdx == (m_RenderConfig.m_NumPipelineThreads - 1)) ?
            // If number of remaining primitives in iteration is not multiple of number of threads, have the last thread cover the remaining range
            (currentDrawElemsStart + primsPerThread + perIterationRemainder) :
            currentDrawElemsStart + primsPerThread;

        // Threads must have been initialized and idle by now!
        PipelineThread* pThread = m_PipelineThreads[threadIdx];

        // Assign computed draw elems range for thread
        pThread-&gt;m_ActiveDrawParams.m_ElemsStart = currentDrawElemsStart;
        pThread-&gt;m_ActiveDrawParams.m_ElemsEnd = currentDrawElemsEnd;
        pThread-&gt;m_ActiveDrawParams.m_VertexOffset = vertexOffset;
        pThread-&gt;m_ActiveDrawParams.m_IsIndexed = isIndexed;

        // PipelineThread drawcall input prepared, it can start processing of drawcall
        pThread-&gt;m_CurrentState.store(ThreadStatus::DRAWCALL_TOP, std::memory_order_release);

        drawElemsPrev = currentDrawElemsEnd;
        numRemainingPrims -= (currentDrawElemsEnd - currentDrawElemsStart);
    }

    // All threads are assigned draw parameters, let them work now
    m_DrawcallSetupComplete.store(true, std::memory_order_release);

    // Stall main thread until all active threads complete given draw iteration
    WaitForPipelineThreadsToCompleteProcessingDrawcall();
}

  for (uint32_t drawIdx = m_ActiveDrawParams.m_ElemsStart, primIdx = m_ActiveDrawParams.m_ElemsStart % m_RenderConfig.m_MaxDrawIterationSize;
    drawIdx < m_ActiveDrawParams.m_ElemsEnd;
    drawIdx++, primIdx++)
{
    // drawIdx = Assigned prim indices which will be only used to fetch indices
    // primIdx = Prim index relative to current iteration

    // Clip-space vertices to be retrieved from VS
    glm::vec4 v0Clip, v1Clip, v2Clip;

    // VS
    ExecuteVertexShader<IsIndexed&gt;(drawIdx, primIdx, &amp;v0Clip, &amp;v1Clip, &amp;v2Clip);

    // Bbox of the primitive which will be computed during clipping
    Rect2D bbox;

    // CLIPPER
    if (!ExecuteFullTriangleClipping(primIdx, v0Clip, v1Clip, v2Clip, &amp;bbox))
    {
        // Triangle clipped, proceed iteration with next primitive
        continue;
    }

    // TRIANGLE SETUP &amp; CULL
    if (!ExecuteTriangleSetupAndCull(primIdx, v0Clip, v1Clip, v2Clip))
    {
        // Triangle culled, proceed iteration with next primitive
        continue;
    }

    // BINNER
    ExecuteBinner(primIdx, v0Clip, v1Clip, v2Clip, bbox);
}



   // First, transform clip-space (x, y, z, w) vertices to device-space 2D homogeneous coordinates (x, y, w)
    const glm::vec4 v0Homogen = TO_HOMOGEN(v0Clip, fbWidth, fbHeight);
    const glm::vec4 v1Homogen = TO_HOMOGEN(v1Clip, fbWidth, fbHeight);
    const glm::vec4 v2Homogen = TO_HOMOGEN(v2Clip, fbWidth, fbHeight);

    // To calculate EE coefficients, we need to set up a "vertex matrix" and invert it
    // M = |  x0  x1  x2  |
    //     |  y0  y1  y2  |
    //     |  w0  w1  w2  |

    // Alternatively, we can rely on the following relation between an inverse and adjoint of a matrix: inv(M) = adj(M)/det(M)
    // Since we use homogeneous coordinates, it's sufficient to only compute adjoint matrix:
    // A = |  a0  b0  c0  |
    //     |  a1  b1  c1  |
    //     |  a2  b2  c2  |

    float a0 = (v2Homogen.y * v1Homogen.w) - (v1Homogen.y * v2Homogen.w);
    float a1 = (v0Homogen.y * v2Homogen.w) - (v2Homogen.y * v0Homogen.w);
    float a2 = (v1Homogen.y * v0Homogen.w) - (v0Homogen.y * v1Homogen.w);

    float b0 = (v1Homogen.x * v2Homogen.w) - (v2Homogen.x * v1Homogen.w);
    float b1 = (v2Homogen.x * v0Homogen.w) - (v0Homogen.x * v2Homogen.w);
    float b2 = (v0Homogen.x * v1Homogen.w) - (v1Homogen.x * v0Homogen.w);

    float c0 = (v2Homogen.x * v1Homogen.y) - (v1Homogen.x * v2Homogen.y);
    float c1 = (v0Homogen.x * v2Homogen.y) - (v2Homogen.x * v0Homogen.y);
    float c2 = (v1Homogen.x * v0Homogen.y) - (v0Homogen.x * v1Homogen.y);

    // Additionally,
    // det(M) == 0 -&gt; degenerate/zero-area triangle
    // det(M) < 0  -&gt; back-facing triangle
    float detM = (c0 * v0Homogen.w) + (c1 * v1Homogen.w) + (c2 * v2Homogen.w);

    // Assign computed EE coefficients for given primitive
    m_pRenderEngine-&gt;m_SetupBuffers.m_pEdgeCoefficients[3 * primIdx + 0] = { a0, b0, c0 };
    m_pRenderEngine-&gt;m_SetupBuffers.m_pEdgeCoefficients[3 * primIdx + 1] = { a1, b1, c1 };
    m_pRenderEngine-&gt;m_SetupBuffers.m_pEdgeCoefficients[3 * primIdx + 2] = { a2, b2, c2 };
} 

// Given a tile size and frame buffer dimensions, find min/max range of the tiles that fall within bbox computed above
    // which we're going to iterate over, in order to determine if the primitive should be binned or not

    // Use floor(), min indices are inclusive
    uint32_t minTileX = static_cast<uint32_t&gt;(glm::floor(bbox.m_MinX / m_RenderConfig.m_TileSize));
    uint32_t minTileY = static_cast<uint32_t&gt;(glm::floor(bbox.m_MinY / m_RenderConfig.m_TileSize));

    // Use ceil(), max indices are exclusive
    uint32_t maxTileX = static_cast<uint32_t&gt;(glm::ceil(bbox.m_MaxX / m_RenderConfig.m_TileSize));
    uint32_t maxTileY = static_cast<uint32_t&gt;(glm::ceil(bbox.m_MaxY / m_RenderConfig.m_TileSize));

     // Fetch edge equation coefficients computed in triangle setup
    glm::vec3 ee0 = m_pRenderEngine->m_SetupBuffers.m_pEdgeCoefficients[3 * primIdx + 0];
    glm::vec3 ee1 = m_pRenderEngine->m_SetupBuffers.m_pEdgeCoefficients[3 * primIdx + 1];
    glm::vec3 ee2 = m_pRenderEngine->m_SetupBuffers.m_pEdgeCoefficients[3 * primIdx + 2];

    // Normalize edge functions
    ee0 /= (glm::abs(ee0.x) + glm::abs(ee0.y));
    ee1 /= (glm::abs(ee1.x) + glm::abs(ee1.y));
    ee2 /= (glm::abs(ee2.x) + glm::abs(ee2.y));

    // Indices of tile corners:
    // LL -> 0  LR -> 1
    // UL -> 2  UR -> 3

    static const glm::vec2 scTileCornerOffsets[] =
    {
        { 0.f, 0.f},                                            // LL
        { m_RenderConfig.m_TileSize, 0.f },                     // LR
        { 0.f, m_RenderConfig.m_TileSize },                     // UL
        { m_RenderConfig.m_TileSize, m_RenderConfig.m_TileSize} // UR
    };

    // (x, y) -> sample location | (a, b, c) -> edge equation coefficients
    // E(x, y) = (a * x) + (b * y) + c
    // E(x + s, y + t) = E(x, y) + (a * s) + (b * t)

    // Based on edge normal n=(a, b), set up tile TR corners for each edge
    const uint8_t edge0TRCorner = (ee0.y >= 0.f) ? ((ee0.x >= 0.f) ? 3u : 2u) : (ee0.x >= 0.f) ? 1u : 0u;
    const uint8_t edge1TRCorner = (ee1.y >= 0.f) ? ((ee1.x >= 0.f) ? 3u : 2u) : (ee1.x >= 0.f) ? 1u : 0u;
    const uint8_t edge2TRCorner = (ee2.y >= 0.f) ? ((ee2.x >= 0.f) ? 3u : 2u) : (ee2.x >= 0.f) ? 1u : 0u;

    // TA corner is the one diagonal from TR corner calculated above
    const uint8_t edge0TACorner = 3u - edge0TRCorner;
    const uint8_t edge1TACorner = 3u - edge1TRCorner;
    const uint8_t edge2TACorner = 3u - edge2TRCorner;

   // Iterate over calculated range of tiles
for (uint32_t ty = minTileY, tyy = 0; ty < maxTileY; ty++, tyy++)
{
    for (uint32_t tx = minTileX, txx = 0; tx < maxTileX; tx++, txx++)
    {
        // Using EE coefficients calculated in TriangleSetup stage and positive half-space tests, determine one of three cases possible for each tile:
        // 1) TrivialReject -- tile within tri's bbox does not intersect tri -&gt; move on
        // 2) TrivialAccept -- tile within tri's bbox is completely within tri -&gt; emit a full-tile coverage mask
        // 3) Overlap       -- tile within tri's bbox intersects tri -&gt; bin the triangle to given tile for further rasterization where block/pixel-level coverage masks will be emitted

        // (txx, tyy) = how many steps are done per dimension
        const float txxOffset = static_cast<float&gt;(txx * m_RenderConfig.m_TileSize);
        const float tyyOffset = static_cast<float&gt;(tyy * m_RenderConfig.m_TileSize);

        // Step from edge function computed above for the first tile in bbox
        float edgeFuncTR0 = edgeFunc0 + ((ee0.x * (scTileCornerOffsets[edge0TRCorner].x + txxOffset)) + (ee0.y * (scTileCornerOffsets[edge0TRCorner].y + tyyOffset)));
        float edgeFuncTR1 = edgeFunc1 + ((ee1.x * (scTileCornerOffsets[edge1TRCorner].x + txxOffset)) + (ee1.y * (scTileCornerOffsets[edge1TRCorner].y + tyyOffset)));
        float edgeFuncTR2 = edgeFunc2 + ((ee2.x * (scTileCornerOffsets[edge2TRCorner].x + txxOffset)) + (ee2.y * (scTileCornerOffsets[edge2TRCorner].y + tyyOffset)));

        // If TR corner of the tile is outside any edge, reject whole tile
        bool TRForEdge0 = (edgeFuncTR0 < 0.f);
        bool TRForEdge1 = (edgeFuncTR1 < 0.f);
        bool TRForEdge2 = (edgeFuncTR2 < 0.f);
        if (TRForEdge0 || TRForEdge1 || TRForEdge2)
        {
            LOG("Tile %d TR'd by thread %d\n", m_pRenderEngine-&gt;GetGlobalTileIndex(tx, ty), m_ThreadIdx);

            // TrivialReject
            // Tile is completely outside of one or more edges
            continue;
        }
        else
        {
            // Tile is partially or completely inside one or more edges, do TrivialAccept tests first

            // Compute edge functions at TA corners based on edge function at first tile origin
            float edgeFuncTA0 = edgeFunc0 + ((ee0.x * (scTileCornerOffsets[edge0TACorner].x + txxOffset)) + (ee0.y * (scTileCornerOffsets[edge0TACorner].y + tyyOffset)));
            float edgeFuncTA1 = edgeFunc1 + ((ee1.x * (scTileCornerOffsets[edge1TACorner].x + txxOffset)) + (ee1.y * (scTileCornerOffsets[edge1TACorner].y + tyyOffset)));
            float edgeFuncTA2 = edgeFunc2 + ((ee2.x * (scTileCornerOffsets[edge2TACorner].x + txxOffset)) + (ee2.y * (scTileCornerOffsets[edge2TACorner].y + tyyOffset)));

            // If TA corner of the tile is outside all edges, accept whole tile
            bool TAForEdge0 = (edgeFuncTA0 &gt;= 0.f);
            bool TAForEdge1 = (edgeFuncTA1 &gt;= 0.f);
            bool TAForEdge2 = (edgeFuncTA2 &gt;= 0.f);
            if (TAForEdge0 &amp;&amp; TAForEdge1 &amp;&amp; TAForEdge2)
            {
                // TrivialAccept
                // Tile is completely inside of the triangle, no further rasterization is needed,
                // whole tile will be fragment-shaded!

                LOG("Tile %d TA'd by thread %d\n", m_pRenderEngine-&gt;GetGlobalTileIndex(tx, ty), m_ThreadIdx);

                // Append tile to the rasterizer queue
                m_pRenderEngine-&gt;EnqueueTileForRasterization(m_pRenderEngine-&gt;GetGlobalTileIndex(tx, ty));

                CoverageMask mask;
                mask.m_SampleX = static_cast<uint32_t&gt;(tilePosX + txxOffset); // Based off of first tile position calculated above
                mask.m_SampleY = static_cast<uint32_t&gt;(tilePosY + tyyOffset); // Based off of first tile position calculated above
                mask.m_PrimIdx = primIdx;
                mask.m_Type = CoverageMaskType::TILE;

                // Emit full-tile coverage mask
                m_pRenderEngine-&gt;AppendCoverageMask(
                    m_ThreadIdx,
                    m_pRenderEngine-&gt;GetGlobalTileIndex(tx, ty),
                    mask);
            }
            else
            {
                LOG("Tile %d binned by thread %d\n", m_pRenderEngine-&gt;GetGlobalTileIndex(tx, ty), m_ThreadIdx);

                // Overlap
                // Tile is partially covered by the triangle, bin the triangle for the tile
                m_pRenderEngine-&gt;BinPrimitiveForTile(
                    m_ThreadIdx,
                    m_pRenderEngine-&gt;GetGlobalTileIndex(tx, ty),
                    primIdx);
            }
        }
    }
}
           // Fetch edge equation coefficients computed in triangle setup
    glm::vec3 ee0 = m_pRenderEngine->m_SetupBuffers.m_pEdgeCoefficients[3 * primIdx + 0];
    glm::vec3 ee1 = m_pRenderEngine->m_SetupBuffers.m_pEdgeCoefficients[3 * primIdx + 1];
    glm::vec3 ee2 = m_pRenderEngine->m_SetupBuffers.m_pEdgeCoefficients[3 * primIdx + 2];

    // Normalize edge functions
    ee0 /= (glm::abs(ee0.x) + glm::abs(ee0.y));
    ee1 /= (glm::abs(ee1.x) + glm::abs(ee1.y));
    ee2 /= (glm::abs(ee2.x) + glm::abs(ee2.y));

    // Indices of tile corners:
    // LL -> 0  LR -> 1
    // UL -> 2  UR -> 3

    static const glm::vec2 scTileCornerOffsets[] =
    {
        { 0.f, 0.f},                                            // LL
        { m_RenderConfig.m_TileSize, 0.f },                     // LR
        { 0.f, m_RenderConfig.m_TileSize },                     // UL
        { m_RenderConfig.m_TileSize, m_RenderConfig.m_TileSize} // UR
    };

    // (x, y) -> sample location | (a, b, c) -> edge equation coefficients
    // E(x, y) = (a * x) + (b * y) + c
    // E(x + s, y + t) = E(x, y) + (a * s) + (b * t)

    // Based on edge normal n=(a, b), set up tile TR corners for each edge
    const uint8_t edge0TRCorner = (ee0.y >= 0.f) ? ((ee0.x >= 0.f) ? 3u : 2u) : (ee0.x >= 0.f) ? 1u : 0u;
    const uint8_t edge1TRCorner = (ee1.y >= 0.f) ? ((ee1.x >= 0.f) ? 3u : 2u) : (ee1.x >= 0.f) ? 1u : 0u;
    const uint8_t edge2TRCorner = (ee2.y >= 0.f) ? ((ee2.x >= 0.f) ? 3u : 2u) : (ee2.x >= 0.f) ? 1u : 0u;

    // TA corner is the one diagonal from TR corner calculated above
    const uint8_t edge0TACorner = 3u - edge0TRCorner;
    const uint8_t edge1TACorner = 3u - edge1TRCorner;
    const uint8_t edge2TACorner = 3u - edge2TRCorner;

  void RenderEngine::BinPrimitiveForTile(uint32_t threadIdx, uint32_t tileIdx, uint32_t primIdx)
{
    // Add primIdx to the per-thread bin of a tile

    std::vector<uint32_t&gt;&amp; tileBin = m_BinList[tileIdx][threadIdx];

    if (tileBin.empty())
    {
        // First encounter of primitive for tile, enqueue it for rasterization
        EnqueueTileForRasterization(tileIdx);
    }
    else
    {
        // Tile must have been already appended to the work queue
        ASSERT(m_TileList[tileIdx].m_IsTileQueued.test_and_set());
    }

    // Append primIdx to the tile's bin
    tileBin.push_back(primIdx);
}

void RenderEngine::EnqueueTileForRasterization(uint32_t tileIdx)
{
    // Append the tile to the rasterizer queue if not already done
    if (!m_TileList[tileIdx].m_IsTileQueued.test_and_set(std::memory_order_acq_rel))
    {
        // Tile not queued up for rasterization, do so now
        m_RasterizerQueue.InsertTileIndex(tileIdx);
    }
}

// To preserve rendering order, we must ensure that all threads finish binning primitives to tiles
// before rasterization is started. To do that, we will stall all threads to sync @DRAWCALL_RASTERIZATION
// Set state to post binning and stall until all PipelineThreads complete binning
m_CurrentState.store(ThreadStatus::DRAWCALL_SYNC_POINT_POST_BINNER, std::memory_order_release);
m_pRenderEngine->WaitForPipelineThreadsToCompleteBinning();

// Position of the block that we're testing at pixel level
float blockPosX = (firstBlockWithinBBoxX + bxxOffset);
float blockPosY = (firstBlockWithinBBoxY + byyOffset);

// Compute E(x, y) = (x * a) + (y * b) c at block origin once
__m128 sseEdge0FuncAtBlockOrigin = _mm_set1_ps(ee0.z + ((ee0.x * blockPosX) + (ee0.y * blockPosY)));
__m128 sseEdge1FuncAtBlockOrigin = _mm_set1_ps(ee1.z + ((ee1.x * blockPosX) + (ee1.y * blockPosY)));
__m128 sseEdge2FuncAtBlockOrigin = _mm_set1_ps(ee2.z + ((ee2.x * blockPosX) + (ee2.y * blockPosY)));

// Store edge 0 equation coefficients
__m128 sseEdge0A4 = _mm_set_ps1(ee0.x);
__m128 sseEdge0B4 = _mm_set_ps1(ee0.y);

// Store edge 1 equation coefficients
__m128 sseEdge1A4 = _mm_set_ps1(ee1.x);
__m128 sseEdge1B4 = _mm_set_ps1(ee1.y);

// Store edge 2 equation coefficients
__m128 sseEdge2A4 = _mm_set_ps1(ee2.x);
__m128 sseEdge2B4 = _mm_set_ps1(ee2.y);

// Generate masks used for tie-breaking rules (not to double-shade along shared edges)
__m128 sseEdge0A4PositiveOrB4NonNegativeA4Zero = _mm_or_ps(_mm_cmpgt_ps(sseEdge0A4, _mm_setzero_ps()),
    _mm_and_ps(_mm_cmpge_ps(sseEdge0B4, _mm_setzero_ps()), _mm_cmpeq_ps(sseEdge0A4, _mm_setzero_ps())));

__m128 sseEdge1A4PositiveOrB4NonNegativeA4Zero = _mm_or_ps(_mm_cmpgt_ps(sseEdge1A4, _mm_setzero_ps()),
    _mm_and_ps(_mm_cmpge_ps(sseEdge1B4, _mm_setzero_ps()), _mm_cmpeq_ps(sseEdge1A4, _mm_setzero_ps())));

__m128 sseEdge2A4PositiveOrB4NonNegativeA4Zero = _mm_or_ps(_mm_cmpgt_ps(sseEdge2A4, _mm_setzero_ps()),
    _mm_and_ps(_mm_cmpge_ps(sseEdge2B4, _mm_setzero_ps()), _mm_cmpeq_ps(sseEdge2A4, _mm_setzero_ps())));

for (uint32_t py = 0; py < g_scPixelBlockSize; py++)
{
    // Store Y positions in current row (all samples on the same row has the same Y position)
    __m128 sseY4 = _mm_set_ps1(py + 0.5f);

    for (uint32_t px = 0; px < g_scNumEdgeTestsPerRow; px++)
    {
        // E(x, y) = (x * a) + (y * b) + c
        // E(x + s, y + t) = E(x, y) + s * a + t * b

        // Store X positions of 4 consecutive samples
        __m128 sseX4 = _mm_setr_ps(
            g_scSIMDWidth * px + 0.5f,
            g_scSIMDWidth * px + 1.5f,
            g_scSIMDWidth * px + 2.5f,
            g_scSIMDWidth * px + 3.5f);

        // a * s
        __m128 sseEdge0TermA = _mm_mul_ps(sseEdge0A4, sseX4);
        __m128 sseEdge1TermA = _mm_mul_ps(sseEdge1A4, sseX4);
        __m128 sseEdge2TermA = _mm_mul_ps(sseEdge2A4, sseX4);

        // b * t
        __m128 sseEdge0TermB = _mm_mul_ps(sseEdge0B4, sseY4);
        __m128 sseEdge1TermB = _mm_mul_ps(sseEdge1B4, sseY4);
        __m128 sseEdge2TermB = _mm_mul_ps(sseEdge2B4, sseY4);

        // E(x+s, y+t) = E(x,y) + a*s + t*b
        __m128 sseEdgeFunc0 = _mm_add_ps(sseEdge0FuncAtBlockOrigin, _mm_add_ps(sseEdge0TermA, sseEdge0TermB));
        __m128 sseEdgeFunc1 = _mm_add_ps(sseEdge1FuncAtBlockOrigin, _mm_add_ps(sseEdge1TermA, sseEdge1TermB));
        __m128 sseEdgeFunc2 = _mm_add_ps(sseEdge2FuncAtBlockOrigin, _mm_add_ps(sseEdge2TermA, sseEdge2TermB));

        //E(x, y):
        //    E(x, y) &gt; 0
        //        ||
        //    !E(x, y) < 0 &amp;&amp; (a &gt; 0 || (a = 0 &amp;&amp; b &gt;= 0))
        //

        // Edge 0 test
        __m128 sseEdge0Positive = _mm_cmpgt_ps(sseEdgeFunc0, _mm_setzero_ps());
        __m128 sseEdge0Negative = _mm_cmplt_ps(sseEdgeFunc0, _mm_setzero_ps());
        __m128 sseEdge0FuncMask = _mm_or_ps(sseEdge0Positive,
            _mm_andnot_ps(sseEdge0Negative, sseEdge0A4PositiveOrB4NonNegativeA4Zero));

        // Edge 1 test
        __m128 sseEdge1Positive = _mm_cmpgt_ps(sseEdgeFunc1, _mm_setzero_ps());
        __m128 sseEdge1Negative = _mm_cmplt_ps(sseEdgeFunc1, _mm_setzero_ps());
        __m128 sseEdge1FuncMask = _mm_or_ps(sseEdge1Positive,
            _mm_andnot_ps(sseEdge1Negative, sseEdge1A4PositiveOrB4NonNegativeA4Zero));

        // Edge 2 test
        __m128 sseEdge2Positive = _mm_cmpgt_ps(sseEdgeFunc2, _mm_setzero_ps());
        __m128 sseEdge2Negative = _mm_cmplt_ps(sseEdgeFunc2, _mm_setzero_ps());
        __m128 sseEdge2FuncMask = _mm_or_ps(sseEdge2Positive,
            _mm_andnot_ps(sseEdge2Negative, sseEdge2A4PositiveOrB4NonNegativeA4Zero));

        // Combine resulting masks of all three edges
        __m128 sseEdgeFuncResult = _mm_and_ps(sseEdge0FuncMask,
            _mm_and_ps(sseEdge1FuncMask, sseEdge2FuncMask));

        uint16_t maskInt = static_cast<uint16_t&gt;(_mm_movemask_ps(sseEdgeFuncResult));

        // If at least one sample is visible, emit coverage mask for the tile
        if (maskInt != 0x0)
        {
            // Quad mask points to the first sample
            CoverageMask mask;
            mask.m_SampleX = static_cast<uint32_t&gt;(blockPosX + (g_scSIMDWidth * px));
            mask.m_SampleY = static_cast<uint32_t&gt;(blockPosY + py);
            mask.m_PrimIdx = primIdx;
            mask.m_Type = CoverageMaskType::QUAD;
            mask.m_QuadMask = maskInt;

            // Emit a quad mask
            m_pRenderEngine-&gt;AppendCoverageMask(m_ThreadIdx, nextTileIdx, mask);
        }
    }
}

// Rasterization completed, set state to post raster and
// stall until all PipelineThreads complete rasterization.
// We need this sync because when (N-x) threads finish rasterization and
// reach the end of tile queue while x threads are still busy rasterizing tile blocks,
// we must ensure that none of the (N-x) non-busy threads will go ahead and start fragment-shading tiles
// whose blocks could be currently still rasterized by x remaining threads
m_CurrentState.store(ThreadStatus::DRAWCALL_SYNC_POINT_POST_RASTER, std::memory_order_release);
m_pRenderEngine->WaitForPipelineThreadsToCompleteRasterization();

auto&amp; currentSlot = pCoverageMaskBuffer-&gt;m_AllocationList[numAlloc];

for (uint32_t numMask = 0; numMask < currentSlot.m_AllocationCount; numMask++)
{
    ASSERT(pCoverageMaskBuffer-&gt;m_AllocationList[numAlloc].m_pData != nullptr);

    CoverageMask* pMask = &amp;currentSlot.m_pData[numMask];

    // In many cases, next N coverage masks will have been generated for the same primitive
    // that we're fragment-shading at tile, block or fragment levels here,
    // it could be optimized so that the EE coefficients of the same primitive won't be fetched
    // from memory over and over again, unsure what gain, if anything it'd yield...

    // First fetch EE coefficients that will be used (in addition to edge in/out tests) for perspective-correct interpolation of vertex attributes
    const glm::vec3 ee0 = m_pRenderEngine-&gt;m_SetupBuffers.m_pEdgeCoefficients[3 * pMask-&gt;m_PrimIdx + 0];
    const glm::vec3 ee1 = m_pRenderEngine-&gt;m_SetupBuffers.m_pEdgeCoefficients[3 * pMask-&gt;m_PrimIdx + 1];
    const glm::vec3 ee2 = m_pRenderEngine-&gt;m_SetupBuffers.m_pEdgeCoefficients[3 * pMask-&gt;m_PrimIdx + 2];

    // Store edge 0 coefficients
    __m128 sseA4Edge0 = _mm_set_ps1(ee0.x);
    __m128 sseB4Edge0 = _mm_set_ps1(ee0.y);
    __m128 sseC4Edge0 = _mm_set_ps1(ee0.z);

    // Store edge 1 equation coefficients
    __m128 sseA4Edge1 = _mm_set_ps1(ee1.x);
    __m128 sseB4Edge1 = _mm_set_ps1(ee1.y);
    __m128 sseC4Edge1 = _mm_set_ps1(ee1.z);

    // Store edge 2 equation coefficients
    __m128 sseA4Edge2 = _mm_set_ps1(ee2.x);
    __m128 sseB4Edge2 = _mm_set_ps1(ee2.y);
    __m128 sseC4Edge2 = _mm_set_ps1(ee2.z);

    const SIMDEdgeCoefficients simdEERegs =
    {
        sseA4Edge0,
        sseA4Edge1,
        sseA4Edge2,
        sseB4Edge0,
        sseB4Edge1,
        sseB4Edge2,
        sseC4Edge0,
        sseC4Edge1,
        sseC4Edge2,
    };

    switch (pMask-&gt;m_Type)
    {
    case CoverageMaskType::TILE:
        LOG("Thread %d fragment-shading tile %d\n", m_ThreadIdx, nextTileIdx);
        FragmentShadeTile(pMask-&gt;m_SampleX, pMask-&gt;m_SampleY, pMask-&gt;m_PrimIdx, simdEERegs);
        break;
    case CoverageMaskType::BLOCK:
        LOG("Thread %d fragment-shading blocks\n", m_ThreadIdx);
        FragmentShadeBlock(pMask-&gt;m_SampleX, pMask-&gt;m_SampleY, pMask-&gt;m_PrimIdx, simdEERegs);
        break;
    case CoverageMaskType::QUAD:
        LOG("Thread %d fragment-shading coverage masks\n", m_ThreadIdx, ee0, ee1, ee2);
        FragmentShadeQuad(pMask, simdEERegs);
        break;
    default:
        ASSERT(false);
        break;
    }
}

   void PipelineThread::ComputeParameterBasisFunctions(
    uint32_t sampleX,
    uint32_t sampleY,
    const SIMDEdgeCoefficients& simdEERegs,
    __m128* pSSEf0XY,
    __m128* pSSEf1XY)
{
    // R(x, y) = F0(x, y) + F1(x, y) + F2(x, y)
    // r = 1/(F0(x, y) + F1(x, y) + F2(x, y))

    // Store X positions of 4 consecutive samples
    __m128 sseX4 = _mm_setr_ps(
        sampleX + 0.5f,
        sampleX + 1.5f,
        sampleX + 2.5f,
        sampleX + 3.5f); // x x+1 x+2 x+3

    // Store Y positions of 4 samples in a row (constant)
    __m128 sseY4 = _mm_set_ps1(sampleY); // y y y y

    // Compute F0(x,y)
    __m128 sseF0XY4 = _mm_add_ps(simdEERegs.m_SSEC4Edge0,
        _mm_add_ps(
            _mm_mul_ps(sseY4, simdEERegs.m_SSEB4Edge0),
            _mm_mul_ps(sseX4, simdEERegs.m_SSEA4Edge0)));

    // Compute F1(x,y)
    __m128 sseF1XY4 = _mm_add_ps(simdEERegs.m_SSEC4Edge1,
        _mm_add_ps(
            _mm_mul_ps(sseY4, simdEERegs.m_SSEB4Edge1),
            _mm_mul_ps(sseX4, simdEERegs.m_SSEA4Edge1)));

    // Compute F2(x,y)
    __m128 sseF2XY4 = _mm_add_ps(simdEERegs.m_SSEC4Edge2,
        _mm_add_ps(
            _mm_mul_ps(sseY4, simdEERegs.m_SSEB4Edge2),
            _mm_mul_ps(sseX4, simdEERegs.m_SSEA4Edge2)));

    // Compute F(x,y) = F0(x,y) + F1(x,y) + F2(x,y)
    __m128 sseR4 = _mm_add_ps(sseF2XY4, _mm_add_ps(sseF0XY4, sseF1XY4));

    // Compute perspective correction factor
    sseR4 = _mm_rcp_ps(sseR4);

    // Assign final f0(x,y) & f1(x,y)
    *pSSEf0XY = _mm_mul_ps(sseR4, sseF0XY4);
    *pSSEf1XY = _mm_mul_ps(sseR4, sseF1XY4);

    // Basis functions f0, f1, f2 sum to 1, e.g. f0(x,y) + f1(x,y) + f2(x,y) = 1 so we'll skip computing f2(x,y) explicitly
}

  
void PipelineThread::FragmentShadeQuad(CoverageMask* pMask, const SIMDEdgeCoefficients& simdEERegs)
{
    FragmentShader FS = m_pRenderEngine->m_FragmentShader;

    // Vertex attributes to be interpolated and passed to FS
    InterpolatedAttributes interpolatedAttribs;

    // Parameter interpolation basis functions
    __m128 ssef0XY, ssef1XY;

    // Calculate basis functions f0(x,y) & f1(x,y) once
    ComputeParameterBasisFunctions(
        pMask->m_SampleX,
        pMask->m_SampleY,
        simdEERegs,            
        &ssef0XY,
        &ssef1XY);

    // Interpolate depth values prior to depth test
    __m128 sseZInterpolated = InterpolateDepthValues(pMask->m_PrimIdx, ssef0XY, ssef1XY);

    // Load current depth buffer contents
    __m128 sseDepthCurrent = m_pRenderEngine->FetchDepthBuffer(pMask->m_SampleX, pMask->m_SampleY);

    // Perform LESS_THAN_EQUAL depth test
    __m128 sseDepthRes = _mm_cmple_ps(sseZInterpolated, sseDepthCurrent);

    // Interpolate active vertex attributes
    InterpolateVertexAttributes(pMask->m_PrimIdx, ssef0XY, ssef1XY, &interpolatedAttribs);

    // 4-sample fragment colors
    FragmentOutput fragmentOutput;

    // Invoke FS and update color/depth buffer with fragment output
    FS(&interpolatedAttribs, m_pRenderEngine->m_pConstantBuffer, &fragmentOutput);

    // Generate color mask from 4-bit int mask set during rasterization
    __m128i sseColorMask = _mm_setr_epi32(
        pMask->m_QuadMask & g_scQuadMask0,
        pMask->m_QuadMask & g_scQuadMask1,
        pMask->m_QuadMask & g_scQuadMask2,
        pMask->m_QuadMask & g_scQuadMask3);

    sseColorMask = _mm_cmpeq_epi32(sseColorMask,
        _mm_set_epi64x(0x800000004, 0x200000001));

    // AND depth mask & coverage mask for quads of fragments
    __m128 sseWriteMask = _mm_and_ps(sseDepthRes, _mm_castsi128_ps(sseColorMask));

    // Write interpolated Z values
    m_pRenderEngine->UpdateDepthBuffer(sseWriteMask, sseZInterpolated, pMask->m_SampleX, pMask->m_SampleY);

    // Write fragment output
    m_pRenderEngine->UpdateColorBuffer(sseWriteMask, fragmentOutput, pMask->m_SampleX, pMask->m_SampleY);
}

  


};
// all information about  video cart
struct Videocart_for_engine
{
  char name_videocart_for_engine;
};
//all  information about RAM 
struct RAM_for_engine  
{
  char name_ram_for_engine;
};

// we render Image  with help some  matrixs.   

int main()
{
    


    
   return 0 ;
}