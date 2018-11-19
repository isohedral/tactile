const U8 tiling_types[81] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 61, 62, 64, 66, 67, 68, 69, 71, 72, 73, 74, 76, 77, 78, 79, 81, 82, 83, 84, 85, 86, 88, 90, 91, 93
};


static const EdgeShape edge_shapes_array_00[] = { J, J, J };
static const EdgeShape edge_shapes_array_01[] = { S, J, S, S, S };
static const EdgeShape edge_shapes_array_02[] = { S, J, J, S };
static const EdgeShape edge_shapes_array_03[] = { S, J, S, J };
static const EdgeShape edge_shapes_array_04[] = { S, S, S };
static const EdgeShape edge_shapes_array_05[] = { S, J };
static const EdgeShape edge_shapes_array_06[] = { J };
static const EdgeShape edge_shapes_array_07[] = { S };
static const EdgeShape edge_shapes_array_08[] = { U, J };
static const EdgeShape edge_shapes_array_09[] = { U, S, S };
static const EdgeShape edge_shapes_array_10[] = { J, I };
static const EdgeShape edge_shapes_array_11[] = { S, I, S };
static const EdgeShape edge_shapes_array_12[] = { I, J };
static const EdgeShape edge_shapes_array_13[] = { I, S };
static const EdgeShape edge_shapes_array_14[] = { U };
static const EdgeShape edge_shapes_array_15[] = { I };
static const EdgeShape edge_shapes_array_16[] = { S, J, J };
static const EdgeShape edge_shapes_array_17[] = { J, J, I };
static const EdgeShape edge_shapes_array_18[] = { S, S, J, S };
static const EdgeShape edge_shapes_array_19[] = { S, S, J, I };
static const EdgeShape edge_shapes_array_20[] = { J, J, S };
static const EdgeShape edge_shapes_array_21[] = { S, I, I };
static const EdgeShape edge_shapes_array_22[] = { J, I, I };
static const EdgeShape edge_shapes_array_23[] = { J, J };
static const EdgeShape edge_shapes_array_24[] = { I, I };
static const EdgeShape edge_shapes_array_25[] = { J, S };
static const EdgeShape edge_shapes_array_26[] = { S, S, S, S };
static const EdgeShape edge_shapes_array_27[] = { J, S, S };
static const EdgeShape edge_shapes_array_28[] = { I, S, I, S };
static const EdgeShape edge_shapes_array_29[] = { J, I, S };
static const EdgeShape edge_shapes_array_30[] = { I, I, I, S };
static const EdgeShape edge_shapes_array_31[] = { S, S };
static const EdgeShape edge_shapes_array_32[] = { S, I };
static const EdgeShape edge_shapes_array_33[] = { U, I };
static const EdgeShape edge_shapes_array_34[] = { U, S };
static const EdgeShape edge_shapes_array_35[] = { I, I, I };
static const EdgeShape edge_shapes_array_36[] = { I, S, I };
static const EdgeShape edge_shapes_array_37[] = { I, S, S };

static const U8 edge_shape_ids_array_00[] = { 0, 1, 2, 0, 1, 2 };
static const U8 edge_shape_ids_array_01[] = { 0, 0, 1, 2, 2, 1 };
static const U8 edge_shape_ids_array_02[] = { 0, 1, 0, 2, 1, 2 };
static const U8 edge_shape_ids_array_03[] = { 0, 1, 2, 3, 1, 4 };
static const U8 edge_shape_ids_array_04[] = { 0, 1, 2, 2, 1, 3 };
static const U8 edge_shape_ids_array_05[] = { 0, 1, 2, 3, 1, 3 };
static const U8 edge_shape_ids_array_06[] = { 0, 0, 1, 1, 2, 2 };
static const U8 edge_shape_ids_array_07[] = { 0, 1, 1, 0, 1, 1 };
static const U8 edge_shape_ids_array_08[] = { 0, 0, 0, 0, 0, 0 };
static const U8 edge_shape_ids_array_09[] = { 0, 1, 2, 0, 2, 1 };
static const U8 edge_shape_ids_array_10[] = { 0, 1, 0, 0, 1, 0 };
static const U8 edge_shape_ids_array_11[] = { 0, 1, 2, 2, 1, 0 };
static const U8 edge_shape_ids_array_12[] = { 0, 1, 1, 1, 1, 0 };
static const U8 edge_shape_ids_array_13[] = { 0, 1, 1, 2, 2 };
static const U8 edge_shape_ids_array_14[] = { 0, 0, 1, 2, 1 };
static const U8 edge_shape_ids_array_15[] = { 0, 1, 2, 3, 2 };
static const U8 edge_shape_ids_array_16[] = { 0, 1, 2, 1, 2 };
static const U8 edge_shape_ids_array_17[] = { 0, 1, 1, 1, 1 };
static const U8 edge_shape_ids_array_18[] = { 0, 1, 2, 0 };
static const U8 edge_shape_ids_array_19[] = { 0, 1, 1, 0 };
static const U8 edge_shape_ids_array_20[] = { 0, 0, 0, 0 };
static const U8 edge_shape_ids_array_21[] = { 0, 1, 0 };
static const U8 edge_shape_ids_array_22[] = { 0, 1, 0, 1 };
static const U8 edge_shape_ids_array_23[] = { 0, 1, 0, 2 };
static const U8 edge_shape_ids_array_24[] = { 0, 0, 1, 1 };
static const U8 edge_shape_ids_array_25[] = { 0, 1, 2, 3 };
static const U8 edge_shape_ids_array_26[] = { 0, 0, 1, 2 };
static const U8 edge_shape_ids_array_27[] = { 0, 1, 2 };
static const U8 edge_shape_ids_array_28[] = { 0, 0, 1 };
static const U8 edge_shape_ids_array_29[] = { 0, 0, 0 };

static const bool edge_orientations_array_00[] = {
	false, false, false, false, false, false, false, true, false, true, false, true };
static const bool edge_orientations_array_01[] = {
	false, false, true, true, false, false, false, false, true, true, false, true };
static const bool edge_orientations_array_02[] = {
	false, false, false, false, true, true, false, false, false, true, true, true };
static const bool edge_orientations_array_03[] = {
	false, false, false, false, false, false, false, false, false, true, false, false };
static const bool edge_orientations_array_04[] = {
	false, false, false, false, false, false, true, true, false, true, false, false };
static const bool edge_orientations_array_05[] = {
	false, false, false, false, false, false, false, false, true, true, true, true };
static const bool edge_orientations_array_06[] = {
	false, false, false, true, false, false, false, true, false, false, false, true };
static const bool edge_orientations_array_07[] = {
	false, false, false, false, false, false, false, false, false, false, false, false };
static const bool edge_orientations_array_08[] = {
	false, false, false, false, true, true, false, false, false, false, true, true };
static const bool edge_orientations_array_09[] = {
	false, false, false, false, true, true, false, true, false, true, true, false };
static const bool edge_orientations_array_10[] = {
	false, false, false, false, false, false, false, true, true, false, true, false };
static const bool edge_orientations_array_11[] = {
	false, false, false, false, true, true, false, true, true, false, true, false };
static const bool edge_orientations_array_12[] = {
	false, false, false, false, false, false, true, false, true, false, true, false };
static const bool edge_orientations_array_13[] = {
	false, false, false, false, false, true, true, true, true, false, true, false };
static const bool edge_orientations_array_14[] = {
	false, false, false, false, true, false, false, false, false, false, true, false };
static const bool edge_orientations_array_15[] = {
	false, false, false, false, false, true, false, false, false, true };
static const bool edge_orientations_array_16[] = {
	false, false, true, true, false, false, false, false, false, true };
static const bool edge_orientations_array_17[] = {
	false, false, false, false, false, false, false, false, false, true };
static const bool edge_orientations_array_18[] = {
	false, false, true, false, false, false, false, false, true, false };
static const bool edge_orientations_array_19[] = {
	false, false, false, false, false, false, true, true, true, true };
static const bool edge_orientations_array_20[] = {
	false, false, false, false, false, true, true, true, true, false };
static const bool edge_orientations_array_21[] = {
	false, false, false, false, false, false, false, true };
static const bool edge_orientations_array_22[] = {
	false, false, false, false, false, true, false, true };
static const bool edge_orientations_array_23[] = {
	false, false, false, false, true, false, true, false };
static const bool edge_orientations_array_24[] = {
	false, false, false, true, false, false, false, true };
static const bool edge_orientations_array_25[] = {
	false, false, true, false, true, true, false, true };
static const bool edge_orientations_array_26[] = {
	false, false, true, false, false, false, true, false };
static const bool edge_orientations_array_27[] = {
	false, false, false, false, false, true };
static const bool edge_orientations_array_28[] = {
	false, false, false, false, true, false };
static const bool edge_orientations_array_29[] = {
	false, false, false, false, false, true, false, false };
static const bool edge_orientations_array_30[] = {
	false, false, false, false, false, true, true, true };
static const bool edge_orientations_array_31[] = {
	false, false, true, true, false, false, true, true };
static const bool edge_orientations_array_32[] = {
	false, false, false, false, true, true, false, false };
static const bool edge_orientations_array_33[] = {
	false, false, false, false, false, false, false, false };
static const bool edge_orientations_array_34[] = {
	false, false, false, false, true, true, true, true };
static const bool edge_orientations_array_35[] = {
	false, false, true, true, false, false, false, false };
static const bool edge_orientations_array_36[] = {
	false, false, false, true, false, false, false, false };
static const bool edge_orientations_array_37[] = {
	false, false, false, false, false, true, true, false };
static const bool edge_orientations_array_38[] = {
	false, false, false, false, true, false, false, false };
static const bool edge_orientations_array_39[] = {
	false, false, true, true, false, true, true, false };
static const bool edge_orientations_array_40[] = {
	false, false, false, true, true, true, true, false };
static const bool edge_orientations_array_41[] = {
	false, false, false, false, false, false };
static const bool edge_orientations_array_42[] = {
	false, false, true, true, false, false };
static const bool edge_orientations_array_43[] = {
	false, false, false, true, false, false };
static const bool edge_orientations_array_44[] = {
	false, false, true, false, false, false };

static const double default_params_array_00[] = {
	0.12239750492, 0.5, 0.143395479017, 0.625 };
static const double default_params_array_01[] = {
	0.12239750492, 0.5, 0.225335752741, 0.225335752741 };
static const double default_params_array_02[] = {
	0.12239750492, 0.5, 0.225335752741, 0.625 };
static const double default_params_array_03[] = {
	0.12239750492, 0.5, 0.315470053838, 0.5, 0.315470053838, 0.5 };
static const double default_params_array_04[] = {
	0.12239750492, 0.5, 0.225335752741, 0.225335752741, 0.5 };
static const double default_params_array_05[] = {
	0.12239750492, 0.5, 0.225335752741, 0.625, 0.5 };
static const double default_params_array_06[] = {
	0.6, 0.196416770201 };
static const double default_params_array_07[] = {
	0.12239750492, 0.5, 0.225335752741 };
static const double default_params_array_08[] = {
	 };
static const double default_params_array_09[] = {
	0.12239750492, 0.225335752741 };
static const double default_params_array_10[] = {
	0.12239750492, 0.225335752741, 0.5 };
static const double default_params_array_11[] = {
	0.12239750492, 0.225335752741, 0.225335752741 };
static const double default_params_array_12[] = {
	0.216506350946 };
static const double default_params_array_13[] = {
	0.104512294489, 0.65 };
static const double default_params_array_14[] = {
	0.230769230769, 0.5, 0.225335752741 };
static const double default_params_array_15[] = {
	0.230769230769, 0.5, 0.225335752741, 0.5 };
static const double default_params_array_16[] = {
	0.230769230769, 0.225335752741 };
static const double default_params_array_17[] = {
	0.141304, 0.465108, 0.534891 };
static const double default_params_array_18[] = {
	0.452827026611, 0.5 };
static const double default_params_array_19[] = {
	0.366873818946 };
static const double default_params_array_20[] = {
	0.230769230769 };
static const double default_params_array_21[] = {
	0.230769230769, 0.5 };
static const double default_params_array_22[] = {
	0.5, 0.102564102564 };
static const double default_params_array_23[] = {
	0.230769230769, 0.869565217391 };
static const double default_params_array_24[] = {
	0.5, 0.230769230769, 0.5, 0.5 };
static const double default_params_array_25[] = {
	0.230769230769, 0.5, 0.230769230769 };
static const double default_params_array_26[] = {
	0.5, 0.5, 0.6 };
static const double default_params_array_27[] = {
	0.5, 0.102564102564, 0.102564102564 };
static const double default_params_array_28[] = {
	0.230769230769, 0.230769230769 };
static const double default_params_array_29[] = {
	0.5 };
static const double default_params_array_30[] = {
	0.105263157895 };
static const double default_params_array_31[] = {
	0.196416770201 };
static const double default_params_array_32[] = {
	0.5, 0.196416770201 };

static const double tiling_vertex_coefficients_array_00[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.9, 0, 0, 0, 0.1, 0, 5, 0, 0, -2.5, 3.9, 0, 5.5, 0, -0.4, 0, 5, 0, -4, 0.5, 3.9, 0, 0, 0, 0.1, 0, 5, 0, 0, -1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -5.5, 0, 0.5, 0, 0, 0, 4, -2 };
static const double tiling_vertex_coefficients_array_01[] = {
	3.9, 0, 0, 0, 0.1, 0, 5, 0, 0, -2.5, 3.9, 0, 0, 3.5, -0.4, 0, 5, 0, 0, -2, 3.9, 0, 0, 0, 0.1, 0, 5, 0, 0, -1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -3.5, 0, 0.5, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_02[] = {
	0, 0, -3.5, 0, 0.5, 0, 0, 0, 4, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.9, 0, 0, 0, 0.1, 0, 5, 0, 0, -2.5, 3.9, 0, 3.5, 0, -0.4, 0, 5, 0, 4, -4.5, 3.9, 0, 0, 0, 0.1, 0, 5, 0, 0, -1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
static const double tiling_vertex_coefficients_array_03[] = {
	0, 0, -2.5, 0, 0, 0, 0.5, 0, 0, 0, 3, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.9, 0, 0, 0, 0, 0, 0.1, 0, 5, 0, 0, 0, 0, -2.5, 3.9, 0, 0, 0, 2.5, 0, -0.4, 0, 5, 0, 0, 0, 3, -3.5, 3.9, 0, 0, 0, 0, 0, 0.1, 0, 5, 0, 0, 0, 0, -1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
static const double tiling_vertex_coefficients_array_04[] = {
	3.9, 0, 0, 3.5, 0, -0.4, 0, 5, 0, 0, 5, -4.5, 3.9, 0, 0, 0, 0, 0.1, 0, 5, 0, 0, 0, -1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -3.5, 0, 0, 0.5, 0, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.9, 0, 0, 0, 0, 0.1, 0, 5, 0, 0, 0, -2.5 };
static const double tiling_vertex_coefficients_array_05[] = {
	3.9, 0, 3.5, 0, 0, -0.4, 0, -5, 0, 4, 0, 0.5, 3.9, 0, 0, 0, 5, -2.4, 0, 5, 0, 0, 0, -1.5, 0, 0, 0, 0, 5, -2.5, 0, 0, 0, 0, 0, 1, 0, 0, -3.5, 0, 0, 0.5, 0, 0, 0, 4, 0, -2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3.9, 0, 0, 0, 0, 0.1, 0, -5, 0, 0, 0, 2.5 };
static const double tiling_vertex_coefficients_array_06[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 0, -0.288675134595, 0, 0, 1, 0, 0, 0, 2.5, 1.12583302492, -0.721132486541, -1.44337567297, 1.95, 1.06036297108, 5, 0, -2.5, 0, 3.9, 0.1, 2.5, -1.12583302492, -1.27886751346, 1.44337567297, 1.95, -0.671687836487 };
static const double tiling_vertex_coefficients_array_07[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 3.9, 0, 0, 0.1, 0, 5, 0, -2.5, 3.9, 0, 3.5, -0.4, 0, 5, 0, -2, 3.9, 0, 0, 0.1, 0, 5, 0, -1.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -3.5, 0.5, 0, 0, 0, 0.5 };
static const double tiling_vertex_coefficients_array_08[] = {
	1, 0, 0.5, 0.866025403784, -0.5, 0.866025403784, -1, 0, -0.5, -0.866025403784, 0.5, -0.866025403784 };
static const double tiling_vertex_coefficients_array_09[] = {
	0, 0, 0, 0, 0, 0, 3.9, 0, 0.1, 0, 0, 0, 3.9, 3.5, -0.4, 0, 0, 0.5, 3.9, 0, 0.1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, -3.5, 0.5, 0, 0, 0.5 };
static const double tiling_vertex_coefficients_array_10[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 3.9, 0, 0, 0.1, 0, 0, 0, 0, 3.9, 3.5, 0, -0.4, 0, 0, 5, -2, 3.9, 0, 0, 0.1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, -3.5, 0, 0.5, 0, 0, 5, -2 };
static const double tiling_vertex_coefficients_array_11[] = {
	3.9, 3.5, -0.4, 0, 0, 0.5, 3.9, 0, 0.1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, -3.5, 0.5, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 3.9, 0, 0.1, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_12[] = {
	0, -3.5, 0, 0.5, 0, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 3.9, 0, 0, 0.1, 0, 0, 0, 0, 3.9, 0, 3.5, -0.4, 0, 0, 0, 0.5, 3.9, 0, 0, 0.1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 };
static const double tiling_vertex_coefficients_array_13[] = {
	0, 0.5, 0, -0.288675134595, 0, 1, 0, 0, 1.15470053838, 0.75, 2, 0.144337567297, 0, 0.5, 4, 0, -1.15470053838, 0.25, 2, 0.144337567297, 0, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_14[] = {
	0, 0, 1, 0, 0, 0, 0, 5, -2.5, 5.1, 0, -0.1, -1.47224318643, 2.5, -1.22113248654, 2.55, 1.44337567297, -0.771687836487, 0, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 0, -0.866025403784 };
static const double tiling_vertex_coefficients_array_15[] = {
	3.9, 0, 0, 0.1, 0, 5, 0, -2.5, 3.9, 0, 3.5, -0.4, 0, 5, 0, -2, 3.9, 0, 0, 0.1, 0, 5, 0, -1.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_16[] = {
	3.9, 0, 0, 0, 0.1, 0, 5, 0, 0, -2.5, 3.9, 0, 3.5, 0, -0.4, 0, 5, 0, 4, -4, 3.9, 0, 0, 0, 0.1, 0, 5, 0, 0, -1.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_17[] = {
	3.9, 0, 0.1, 0, 0, 0, 3.9, 3.5, -0.4, 0, 0, 0.5, 3.9, 0, 0.1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_18[] = {
	0, 0, 5, -2.5, 0, 0, 0, 1, 0, 0, -5, 2.5, 0, 10, 0, -4, 0, 0, 0, 0, 0, 0, 0, 0, 3.9, 0, 0, 0.1, 0, -5, 0, 2.5, 3.9, 0, 5, -2.4, 0, 5, 0, -1.5 };
static const double tiling_vertex_coefficients_array_19[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1.95, 2.5, -0.95, -1.95, 2.5, -1.05, 3.9, 0, 0.1, 0, 5, -2, 1.95, -2.5, 1.55, 1.95, 2.5, -0.45 };
static const double tiling_vertex_coefficients_array_20[] = {
	0, -1, 0, 0, 0, 1, 0, 0, 4.95, 0.55, 4.95, 0.55, 0, 0, 9.9, 0.1, -4.95, -0.55, 4.95, 0.55 };
static const double tiling_vertex_coefficients_array_21[] = {
	0, 1, 0, 0, 2.925, 0.075, 1.68874953738, 0.0433012701892, 0, 0, 0, 0, -2.925, 1.425, 1.68874953738, -0.822724133595 };
static const double tiling_vertex_coefficients_array_22[] = {
	1, 0, 0.75, 0.433012701892, 0, 0, 0.75, -0.433012701892 };
static const double tiling_vertex_coefficients_array_23[] = {
	0.5, 0, 0, 0.866025403784, -0.5, 0, 0, -0.866025403784 };
static const double tiling_vertex_coefficients_array_24[] = {
	0, 0.57735026919, -1, 0, 1, 0 };
static const double tiling_vertex_coefficients_array_25[] = {
	0, 0, 0, 0, 0, 0, 3.9, 0, 0.1, 0, 5, -2.5, 3.9, 0, 0.1, 0, 5, -1.5, 0, 0, 0, 0, 0, 1 };
static const double tiling_vertex_coefficients_array_26[] = {
	5, 0, -2, 0, -3.9, -0.1, 0, 0, 1, 0, 0, 0, 5, 0, -2, 0, 3.9, 0.1, 0, 0, 0, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_27[] = {
	0, 0, 1, 0, 0, 0, 0, -3.45, 4, 3.9, 0, 0.1, 0, 3.45, -3, 3.9, 0, 0.1, 0, 0, 0, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_28[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, 0, 0, 0, -1.5, 0, 3.9, 0, 0, 0.1, 0, 0, 5, 0, -2.5, 0, 0, 0, 5, -1.5 };
static const double tiling_vertex_coefficients_array_29[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -5, 3.9, 2.6, 3.9, 0, 0, 0.1, 0, -5, 0, 2.5, 3.9, 0, 0, 0.1 };
static const double tiling_vertex_coefficients_array_30[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -10, 0, 0, 5, 0, 10, 0, -4, 10, 0, 10, -10, 0, 10, 0, -5, 0, 0, 10, -5 };
static const double tiling_vertex_coefficients_array_31[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 3.9, 0.1, 0, 0, 3.9, 0.1 };
static const double tiling_vertex_coefficients_array_32[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 0, 3.9, 0.1, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, -2, 0, -3.9, 0, -0.1 };
static const double tiling_vertex_coefficients_array_33[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 3.9, 0, 0.1, 0, 0, 0, 3.9, 0, 0.1, 0, 3.9, 0.1 };
static const double tiling_vertex_coefficients_array_34[] = {
	1, 0, 1, 1, 0, 1, 0, 0 };
static const double tiling_vertex_coefficients_array_35[] = {
	1.8, 0.1, 0, 0, 0, 1, 0, 1, 0, 0, -1.8, 1.9, 0, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_36[] = {
	3.8, 0.1, 0, 0, 0, 0, -3.8, 0.9, -3.8, -0.1, 0, 0, 0, 0, 3.8, -0.9 };
static const double tiling_vertex_coefficients_array_37[] = {
	0, 0, 0.57735026919, 0, 0, 1 };
static const double tiling_vertex_coefficients_array_38[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3.9, 0.1 };
static const double tiling_vertex_coefficients_array_39[] = {
	0.5, 0.5, 0, 0, 1, 0 };
static const double tiling_vertex_coefficients_array_40[] = {
	0, 1, 0, 0, 0, 0.5, 3.9, 0.1, 0, 0, 0, 0 };
static const double tiling_vertex_coefficients_array_41[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 5, 0, -2, 0, 3.9, 0.1 };
static const double tiling_vertex_coefficients_array_42[] = {
	1, 0, -0.5, 0.866025403784, -0.5, -0.866025403784 };

static const double translation_coefficients_array_00[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 3.9, 0, 5.5, 0, -0.4, 0, 5, 0, -4, -0.5 };
static const double translation_coefficients_array_01[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7.8, 0, 3.5, 3.5, -0.8, 0, 0, -1.66533453694e-16, 7.95659834315e-16, 0 };
static const double translation_coefficients_array_02[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -7.8, -3.33066907388e-16, -7, 0, 0.8, 0, -2.22044604925e-16, -1.11022302463e-15, -2.22044604925e-16, -1 };
static const double translation_coefficients_array_03[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -7.8, 1.11022302463e-16, -2.5, 0, -2.5, 0, 0.8, 0, -10, 0, 3, 0, -3, 4 };
static const double translation_coefficients_array_04[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -15.6, 0, -7, -7, 0, 1.6, 0, 0, 4.4408920985e-16, 0, 0, -2 };
static const double translation_coefficients_array_05[] = {
	-2.65990932983e-16, 0, -3.70074341542e-17, 0, -2.22044604925e-16, 1.91976064675e-16, 8.881784197e-16, 10, 0, 4.4408920985e-16, 0, -3, 7.8, 3.33066907388e-16, 7, 3.33066907388e-16, 7.77156117238e-16, -0.8, -7.40148683083e-17, -1.48029736617e-16, 2.22044604925e-16, -1.48029736617e-16, 0, 7.40148683083e-17 };
static const double translation_coefficients_array_06[] = {
	-2.5, -3.37749907476, 0.663397459622, 4.33012701892, -1.95, -3.08108891325, -2.5, 3.37749907476, 2.33660254038, -4.33012701892, -1.95, 2.11506350946 };
static const double translation_coefficients_array_07[] = {
	0, 0, 7.40148683083e-17, 0, 0, 0, 0, -1, 7.8, 0, 7, -0.8, 0, 0, 5.92118946467e-16, 0 };
static const double translation_coefficients_array_08[] = {
	1.5, 0.866025403784, 1.5, -0.866025403784 };
static const double translation_coefficients_array_09[] = {
	1.5, 0.866025403784, 7.40148683083e-17, 1.73205080757 };
static const double translation_coefficients_array_10[] = {
	0, 0, 0, 0, 0, -1, 3.9, 3.5, -0.4, 0, 1.11022302463e-16, -0.5 };
static const double translation_coefficients_array_11[] = {
	0, 0, 0, 0, -3.33066907388e-16, 0, -3.33066907388e-16, -1, 7.8, 7, 0, -0.8, 0, -4.4408920985e-16, -7.40148683083e-17, 0 };
static const double translation_coefficients_array_12[] = {
	3.9, 3.5, -0.4, 0, -1.66533453694e-16, 0.5, 3.9, 3.5, -0.4, 0, 0, -0.5 };
static const double translation_coefficients_array_13[] = {
	4.62592926927e-18, 1.66533453694e-16, -1.48029736617e-16, -4.62592926927e-18, -2.22044604925e-16, 0, 0, -1, -7.8, -3.5, -3.5, 0.8, 0, 0, 0, 0 };
static const double translation_coefficients_array_14[] = {
	6.38378239159e-16, 1.01770443924e-16, -4, -0.866025403784, 3.46410161514, 0.75, -2, -0.433012701892 };
static const double translation_coefficients_array_15[] = {
	4.4167295593, -2.5, 2.66339745962, -2.55, -4.33012701892, 1.34903810568, -1.7763568394e-15, -5, 2.5, -5.1, 1.99840144433e-15, -1.63205080757 };
static const double translation_coefficients_array_16[] = {
	-7.8, 0, -3.5, 0.3, 0, 0, 6.66133814775e-16, -0.5, -7.8, 0, -3.5, 0.3, 0, 0, -1.66533453694e-16, 0.5 };
static const double translation_coefficients_array_17[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7.8, -1.66533453694e-16, 3.5, 0, -0.3, 0, 10, 0, 4, -7.5 };
static const double translation_coefficients_array_18[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 15.6, 5.55111512313e-16, 7, 5.55111512313e-16, -0.6, 0, 6.2172489379e-16, 4.88498130835e-16, 4.88498130835e-16, -4.88498130835e-16 };
static const double translation_coefficients_array_19[] = {
	0, 0, 0, 0, 0, 0, 0, 1, -15.6, 0, -7, 0.6, 0, 0, -4.66293670343e-16, 0 };
static const double translation_coefficients_array_20[] = {
	-1.66533453694e-17, -1.99840144433e-16, 1.66533453694e-17, 0, 0, 1, -7.8, -3.5, 0.3, 0, 0, 0.5 };
static const double translation_coefficients_array_21[] = {
	3.99680288865e-16, 2.6645352591e-16, 1.33226762955e-15, -4.4408920985e-16, 0, 10, 0, -3, -7.8, 1.7763568394e-15, -10, 4.8, 0, 1.33226762955e-16, 0, -1.33226762955e-16 };
static const double translation_coefficients_array_22[] = {
	-3.9, 5, -3.1, -3.9, -5, 1.9, -3.9, -5, 1.9, 3.9, -5, 3.1 };
static const double translation_coefficients_array_23[] = {
	9.9, 1.1, -9.9, -1.1, -9.9, -1.1, -9.9, -1.1 };
static const double translation_coefficients_array_24[] = {
	-3.88578058619e-16, 2.77555756156e-16, 0, 1.73205080757, -2.22044604925e-16, 1.5, -2.22044604925e-16, -0.866025403784 };
static const double translation_coefficients_array_25[] = {
	-1.5, 0.866025403784, -1.5, -0.866025403784 };
static const double translation_coefficients_array_26[] = {
	0, 1.73205080757, 1.5, -0.866025403784 };
static const double translation_coefficients_array_27[] = {
	-1, 1.73205080757, 1, 1.73205080757 };
static const double translation_coefficients_array_28[] = {
	1, 1.73205080757, -1, 1.73205080757 };
static const double translation_coefficients_array_29[] = {
	1, 1.73205080757, 2, 7.40148683083e-17 };
static const double translation_coefficients_array_30[] = {
	0, 0, 0, 0, 0, -1, 3.9, 0, 0.1, 0, 5, -2.5 };
static const double translation_coefficients_array_31[] = {
	0, 0, 0, 0, 0, -1, 7.8, 0, 0.2, 0, 0, 0 };
static const double translation_coefficients_array_32[] = {
	-1.94289029309e-16, -8.32667268469e-17, 8.32667268469e-17, 2.77555756156e-17, -7.8, -0.2, -6.66133814775e-16, 0, 1, 1.2490009027e-16, 4.16333634234e-17, -4.16333634234e-17 };
static const double translation_coefficients_array_33[] = {
	0, -6.9, 8, 0, 0, 0, 0, -3.45, 4, -3.9, -2.77555756156e-17, -0.1 };
static const double translation_coefficients_array_34[] = {
	-5, 0, -5, 0, 5, 0, -3.9, 0, -5, 1.4, -5, 0, 0, 0, 1.5, 5.55111512313e-17, -3.9, 0, -5.55111512313e-17, -0.1 };
static const double translation_coefficients_array_35[] = {
	0, 0, 0, 0, 0, -1, 7.8, 0, 0.2, 0, 10, -5 };
static const double translation_coefficients_array_36[] = {
	0, 0, 0, 0, -7.8, 0, 0, -0.2, 0, 4.4408920985e-16, 3.9, 1.1, -8.881784197e-16, 2.42861286637e-17, -1.38777878078e-17, 0 };
static const double translation_coefficients_array_37[] = {
	-15.6, 0, -0.4, 0, 0, 0, 0, 0, 0, 0, 0, -1 };
static const double translation_coefficients_array_38[] = {
	0, -4.4408920985e-16, 0, 0, -20, 0, -20, 20, 0, -4.4408920985e-16, 0, -2, -2.44249065418e-15, -3.5527136788e-15, -2.44249065418e-15, 2.44249065418e-15 };
static const double translation_coefficients_array_39[] = {
	4.4408920985e-16, 2, 2.08166817117e-17, -2.08166817117e-17, 0, 0, -7.8, -0.2 };
static const double translation_coefficients_array_40[] = {
	0, 0, 0, -1, 0, 0, 0, 0, 2.22044604925e-16, 0, 0, 0, 0, -7.8, -7.8, -0.4 };
static const double translation_coefficients_array_41[] = {
	-7.8, 0, -0.2, 0, 6.24500451352e-17, -6.24500451352e-17, -3.9, -2.77555756156e-17, -0.1, 2.22044604925e-16, 3.9, 1.1 };
static const double translation_coefficients_array_42[] = {
	0, 2, 2, 0 };
static const double translation_coefficients_array_43[] = {
	1.80411241502e-17, -2.63677968348e-17, 8.881784197e-16, 4, 4.4408920985e-16, -2, 0, 2 };
static const double translation_coefficients_array_44[] = {
	-3.12250225676e-17, 3.12250225676e-17, -7.6, 1.8, 7.6, 0.2, -7.6, 1.8 };
static const double translation_coefficients_array_45[] = {
	1, 1, 1, -1 };
static const double translation_coefficients_array_46[] = {
	1, 0, 0, 1 };
static const double translation_coefficients_array_47[] = {
	0, 0, -3.9, -0.1, 0, 1, 1.38777878078e-17, -1.38777878078e-17 };
static const double translation_coefficients_array_48[] = {
	0, 0, -3.9, -0.1, 0, 2, -1.38777878078e-17, 1.38777878078e-17 };
static const double translation_coefficients_array_49[] = {
	0, -3.45, 4, -3.9, 2.77555756156e-17, -0.1, 0, -3.45, 4, 3.9, 0, 0.1 };
static const double translation_coefficients_array_50[] = {
	3.8, 0.1, -3.8, 0.9, -3.8, -0.1, -3.8, 0.9 };
static const double translation_coefficients_array_51[] = {
	-2.22044604925e-16, 2, -1.73205080757, 1 };
static const double translation_coefficients_array_52[] = {
	4.4408920985e-16, 2, -1.38777878078e-17, 1.38777878078e-17, 0, 1, 3.9, 0.1 };
static const double translation_coefficients_array_53[] = {
	0, 1, -1, 0 };
static const double translation_coefficients_array_54[] = {
	-1, 1, -2, 0 };
static const double translation_coefficients_array_55[] = {
	0, 1, 1, 0 };
static const double translation_coefficients_array_56[] = {
	0, 0.5, -3.9, -0.1, 0, -0.5, -3.9, -0.1 };
static const double translation_coefficients_array_57[] = {
	-5, 0, 2, 2.77555756156e-17, -3.9, -0.1, -5, 0, 3, 0, -3.9, -0.1 };
static const double translation_coefficients_array_58[] = {
	0, 0, 1, -2.77555756156e-17, -1.38777878078e-17, 1.38777878078e-17, 0, 0, 0, -8.32667268469e-17, 7.8, 0.2 };
static const double translation_coefficients_array_59[] = {
	2.22044604925e-16, 1, -3.00685402503e-16, 4.62592926927e-18, -3.33066907388e-16, 1.11022302463e-16, 7.8, 0.2 };
static const double translation_coefficients_array_60[] = {
	-1.5, 2.59807621135, -3, -1.33226762955e-15 };
static const double translation_coefficients_array_61[] = {
	0, -0.5, -3.9, -0.1, 0, 0.5, -3.9, -0.1 };

static const double aspect_coefficients_array_00[] = {
	0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };
static const double aspect_coefficients_array_01[] = {
	0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, -2.22044604925e-16, -1, 0, 0, 0, 0, 0, 7.8, 0, 0, 3.5, -0.3, 0, 0, 0, 0, 0, 0, 0, 0, 2.22044604925e-16, 1, 0, 0, 0, 8.881784197e-16, -0.5 };
static const double aspect_coefficients_array_02[] = {
	0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -3.9, -2.77555756156e-16, -3.5, -2.77555756156e-16, 0.4, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 5, -8.881784197e-16, 4, -4.5 };
static const double aspect_coefficients_array_03[] = {
	0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -2.5, 0, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 3, 0, 0, -1 };
static const double aspect_coefficients_array_04[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 7.8, 5.55111512313e-17, 0, 3.5, 0, -0.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 10, 0, 0, 5, -6, 0, 0, -2.22044604925e-16, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -3.5, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 2.22044604925e-16, 0, 0, 1, 0, 0, -2.22044604925e-16, 0, 0, -0.5, 0, 0, 2.22044604925e-16, 0, 0, 1, 0, 0, 0, 0, 0, -0, -7.8, 1.11022302463e-16, -3.5, -3.5, 1.11022302463e-16, 0.8, 0, 0, 0, 0, 0, 0, 0, 0, -2.22044604925e-16, 0, 0, -1, 0, 10, -1.7763568394e-15, 0, 5, -7.5 };
static const double aspect_coefficients_array_05[] = {
	0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1.11022302463e-16, 0, -1, 0, 0, 0, 5.55111512313e-17, 0, 0, 7.8, 0, 3.5, 0, 5, -2.8, 0, 0, 0, -5.55111512313e-17, 0, 0, 0, 0, 0, 1.11022302463e-16, 0, -1, 0, -4.4408920985e-16, 0, 4, 0, -1, 3.33066907388e-16, 0, 0, 0, 0, -1, 2.77555756156e-17, 5.55111512313e-17, 0, 0, 0, -2.77555756156e-17, 3.9, 0, 0, 0, 5, -2.4, 2.77555756156e-17, 5.55111512313e-17, 0, 0, 0, -2.77555756156e-17, -3.33066907388e-16, 0, 0, 0, 0, 1, 2.22044604925e-16, 5, 0, 0, 0, -1.5, -3.33066907388e-16, 0, 0, -2.22044604925e-16, 0, 1, -2.77555756156e-17, -5.55111512313e-17, 0, 5.55111512313e-17, 0, 2.77555756156e-17, 3.9, 0, 3.5, -4.4408920985e-16, 4.4408920985e-16, -0.4, -2.77555756156e-17, -5.55111512313e-17, 0, 5.55111512313e-17, 0, 2.77555756156e-17, 3.33066907388e-16, 0, 0, 2.22044604925e-16, 0, -1, -2.22044604925e-16, -5, 0, 4, 0, 0.5 };
static const double aspect_coefficients_array_06[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -0.5, 0, 0, -0.866025403784, 0, 0, 0.5, 0, 0, 0.866025403784, 0, 0, -0.5, 0, 0, -0.866025403784, 0, 0, -0.5, 0, 0, 0.866025403784, 0, 0, 1, 0, 0, -0.866025403784, 0, 0, -0.5, 0, 0, 0 };
static const double aspect_coefficients_array_07[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, -2.22044604925e-16, -1, 0, 0, 0, 0, 7.8, 0, 3.5, -0.3, 0, 0, 0, 0, 0, 0, 2.22044604925e-16, 1, 0, 0, 8.881784197e-16, -0.5 };
static const double aspect_coefficients_array_08[] = {
	1, 0, 0, 0, 1, 0 };
static const double aspect_coefficients_array_09[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 };
static const double aspect_coefficients_array_10[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 7.8, 3.5, 0, -0.3, 0, 0, 0, 0, 0, 0, 0, -1, 0, -4.4408920985e-16, 5, -2 };
static const double aspect_coefficients_array_11[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -3.5, 0, 0.5, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0.5 };
static const double aspect_coefficients_array_12[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0.5, 0, 0.866025403784, 0, 0.5, 0, 0.866025403784, 0, -0.5, 0, -0.866025403784, 0, -0.5, 0, -0.866025403784, 0, 0.5, 0, 0.866025403784, 0, -0.5, 0, -0.866025403784 };
static const double aspect_coefficients_array_13[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0.5, 0, 0, 0.866025403784, 0, 0, 1, 0, 0, -0.866025403784, 0, 0, 0.5, 0, 0, 0, 0, 0, -0.5, 0, 0, 0.866025403784, 0, 0, 1.5, 0, 0, -0.866025403784, 0, 0, -0.5, 0, 0, -0.866025403784, 0, 0, -1, 0, 0, -4.99600361081e-16, 0, 0, 1, 0, 0, 4.99600361081e-16, 0, 0, -1, 0, 0, -1.73205080757, 0, 0, -0.5, 0, 0, -0.866025403784, 0, 0, -8.881784197e-16, 0, 0, 0.866025403784, 0, 0, -0.5, 0, 0, -1.73205080757, 0, 0, 0.5, 0, 0, -0.866025403784, 0, 0, -0.5, 0, 0, 0.866025403784, 0, 0, 0.5, 0, 0, -0.866025403784 };
static const double aspect_coefficients_array_14[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 };
static const double aspect_coefficients_array_15[] = {
	0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1.11022302463e-16, -1.11022302463e-16, -1, 0, 0, -5.55111512313e-17, -5.55111512313e-17, 5.55111512313e-17, 7.8, 0, 3.5, 1.11022302463e-16, -0.3, 0, 0, 5.55111512313e-17, 5.55111512313e-17, -5.55111512313e-17, 0, 0, -1.11022302463e-16, -1.11022302463e-16, -1, 0, 10, 0, 4, -6.5 };
static const double aspect_coefficients_array_16[] = {
	0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1.11022302463e-16, -1.11022302463e-16, -1, 0, 0, -5.55111512313e-17, -5.55111512313e-17, 5.55111512313e-17, 7.8, 0, 3.5, 1.11022302463e-16, -0.3, 0, 0, 5.55111512313e-17, 5.55111512313e-17, -5.55111512313e-17, 0, 0, -1.11022302463e-16, -1.11022302463e-16, -1, 0, 10, 0, 4, -6.5, 0, 0, -2.22044604925e-16, -2.22044604925e-16, -1, 0, 0, 0, 0, 0, 15.6, 5.55111512313e-16, 7, 5.55111512313e-16, -0.6, 0, 0, 0, 0, 0, 0, 0, 2.22044604925e-16, 2.22044604925e-16, 1, 0, 1.33226762955e-15, 8.881784197e-16, 8.881784197e-16, -8.881784197e-16, 0, 0, 1.11022302463e-16, 1.11022302463e-16, 1, 0, 0, -5.55111512313e-17, -5.55111512313e-17, 5.55111512313e-17, 7.8, 0, 3.5, 1.11022302463e-16, -0.3, 0, 0, -5.55111512313e-17, -5.55111512313e-17, 5.55111512313e-17, 0, 0, -1.11022302463e-16, -1.11022302463e-16, -1, 0, 10, 0, 4, -6.5 };
static const double aspect_coefficients_array_17[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -0, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, -2.22044604925e-16, -1, 0, 0, 0, 0, -7.8, 0, -3.5, 0.3, 0, 0, 0, 0, 0, 0, 2.22044604925e-16, 1, 0, 0, -2.22044604925e-16, -0.5, 0, 0, 2.22044604925e-16, 1, 0, 0, 0, 0, -7.8, 0, -3.5, 0.3, 0, 0, 0, 0, 0, 0, -2.22044604925e-16, -1, 0, 0, 0, 0.5 };
static const double aspect_coefficients_array_18[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -0, 0, 0, -1, 0, 0, 1 };
static const double aspect_coefficients_array_19[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 10, 0, -3, 0, 3.33066907388e-16, 0, 1, 0, 0, 0, 0, -3.9, 4.4408920985e-16, -5, 2.4, 0, 0, 0, 0, 0, -3.33066907388e-16, 0, -1, 0, 5, 2.22044604925e-16, -1.5, 0, -3.33066907388e-16, 0, -1, 0, 0, 0, -0, 3.9, -4.4408920985e-16, 5, -2.4, 0, 0, 0, 0, 0, 3.33066907388e-16, 0, 1, 0, 5, -2.22044604925e-16, -1.5 };
static const double aspect_coefficients_array_20[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -0, 0, 0, -1, 0, 0, 1, 1.66533453694e-16, 1.11022302463e-16, -1.11022302463e-16, 1.11022302463e-16, 2.22044604925e-16, -1, -3.9, -1.11022302463e-16, -0.1, -1.11022302463e-16, -2.22044604925e-16, 1, 1.66533453694e-16, 1.11022302463e-16, -1.11022302463e-16, 0, -5, 3, 0, -5.55111512313e-17, 0, 2.22044604925e-16, 4.4408920985e-16, 1, -3.9, -4.4408920985e-16, -1.1, -2.22044604925e-16, -4.4408920985e-16, -1, 0, -5.55111512313e-17, 0, 0, -5, 3 };
static const double aspect_coefficients_array_21[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, -0, 0, 0, 0, -0, 0, -1, 0, 0, -1.11022302463e-16, 1.11022302463e-16, -1.11022302463e-16, -1, 9.9, 1.1, 1.11022302463e-16, 1, -1.11022302463e-16, 1.11022302463e-16, 2.08166817117e-17, -2.08166817117e-17, 8.32667268469e-17, -8.32667268469e-17, 0, 1, -9.9, -1.1, 0, 1, -8.32667268469e-17, 8.32667268469e-17, -1.7763568394e-15, 1.11022302463e-16 };
static const double aspect_coefficients_array_22[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1.11022302463e-16, -0.5, -1.11022302463e-16, 0.866025403784, 0, 1.5, 1.11022302463e-16, -0.866025403784, 1.11022302463e-16, -0.5, -1.11022302463e-16, 0.866025403784, 1.11022302463e-16, -0.5, 3.33066907388e-16, -0.866025403784, 0, 1.5, -3.33066907388e-16, 0.866025403784, 1.11022302463e-16, -0.5, 1.11022302463e-16, -0.866025403784, -2.22044604925e-16, 0.5, 0, 0.866025403784, 0, 0, 0, 0.866025403784, 2.22044604925e-16, -0.5, 0, 0, 3.33066907388e-16, -1, -1.11022302463e-16, 1.11022302463e-16, -4.4408920985e-16, 1.5, -1.11022302463e-16, 1.11022302463e-16, -3.33066907388e-16, 1, 2.22044604925e-16, 0.866025403784, -1.66533453694e-16, 0.5, 5.55111512313e-16, -0.866025403784, 2.22044604925e-16, 0, 5.55111512313e-16, -0.866025403784, 1.66533453694e-16, -0.5, -4.4408920985e-16, 1.73205080757 };
static const double aspect_coefficients_array_23[] = {
	1, 0, 0, 0, 1, 0, 0.5, -0.866025403784, 0, 0.866025403784, 0.5, 0, -0.5, -0.866025403784, 0, 0.866025403784, -0.5, 0, -1, -1.11022302463e-16, 0, 1.11022302463e-16, -1, 0, -0.5, 0.866025403784, 0, -0.866025403784, -0.5, 0, 0.5, 0.866025403784, 0, -0.866025403784, 0.5, 0 };
static const double aspect_coefficients_array_24[] = {
	1, 0, 0, 0, 1, 0, -0.5, -0.866025403784, 1.5, 0.866025403784, -0.5, -0.866025403784, -0.5, 0.866025403784, 1.5, -0.866025403784, -0.5, 0.866025403784, 0.5, 0.866025403784, 0, 0.866025403784, -0.5, 0, 0.5, -0.866025403784, 0, -0.866025403784, -0.5, 1.73205080757, -1, -2.77555756156e-16, 1.5, -2.77555756156e-16, 1, 0.866025403784 };
static const double aspect_coefficients_array_25[] = {
	1, 0, 0, 0, 1, 0, -0.5, 0.866025403784, 0.75, -0.866025403784, -0.5, 0.433012701892, -0.5, -0.866025403784, 0.75, 0.866025403784, -0.5, -0.433012701892 };
static const double aspect_coefficients_array_26[] = {
	1, 0, 0, 0, 1, 0, 0.5, -0.866025403784, 0.75, 0.866025403784, 0.5, 0.433012701892, -0.5, -0.866025403784, 0.75, 0.866025403784, -0.5, 1.29903810568 };
static const double aspect_coefficients_array_27[] = {
	1, 0, 0, 0, 1, 0, 0.5, 0.866025403784, 0.75, 0.866025403784, -0.5, 0.433012701892, -0.5, -0.866025403784, 0.75, 0.866025403784, -0.5, -0.433012701892 };
static const double aspect_coefficients_array_28[] = {
	1, 0, 0, 0, 1, 0, -0.5, -0.866025403784, 0.75, -0.866025403784, 0.5, 0.433012701892, -0.5, 0.866025403784, 0.75, 0.866025403784, 0.5, -0.433012701892 };
static const double aspect_coefficients_array_29[] = {
	1, 0, 0, 0, 1, 0, -0.5, 0.866025403784, -0.5, -0.866025403784, -0.5, 0.866025403784, -0.5, -0.866025403784, 0.5, 0.866025403784, -0.5, 0.866025403784, -0.5, 0.866025403784, -1.5, 0.866025403784, 0.5, 0.866025403784, -0.5, -0.866025403784, -0.5, -0.866025403784, 0.5, 0.866025403784, 1, 0, -1, 0, -1, 1.73205080757 };
static const double aspect_coefficients_array_30[] = {
	1, 0, 0, 0, 1, 0, -0.5, 0.866025403784, -0.5, -0.866025403784, -0.5, 0.866025403784, -0.5, -0.866025403784, 0.5, 0.866025403784, -0.5, 0.866025403784, 0.5, -0.866025403784, -0.5, 0.866025403784, 0.5, 0.866025403784, 0.5, 0.866025403784, -1.5, -0.866025403784, 0.5, 0.866025403784, -1, -1.11022302463e-16, -1, 1.11022302463e-16, -1, 1.73205080757 };
static const double aspect_coefficients_array_31[] = {
	1, 0, 0, 0, 1, 0, -0.5, -0.866025403784, 0.5, 0.866025403784, -0.5, 0.866025403784, -0.5, 0.866025403784, -0.5, -0.866025403784, -0.5, 0.866025403784, 0.5, 0.866025403784, 0.5, -0.866025403784, 0.5, 0.866025403784, 0.5, -0.866025403784, 1.5, 0.866025403784, 0.5, 0.866025403784, -1, 1.11022302463e-16, 1, -1.11022302463e-16, -1, 1.73205080757 };
static const double aspect_coefficients_array_32[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 7.8, 0, 0.2, 0, 0, 0, 0, 0, 1, 0, 0, 0 };
static const double aspect_coefficients_array_33[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3.9, 0, 0.1, 0, 0, 0, 0, 0, -1, 0, 5, -1.5 };
static const double aspect_coefficients_array_34[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -3.33066907388e-16, -1.11022302463e-16, -1, 0, 0, 0, 5, 0, -1, 0, 0, 0, 3.33066907388e-16, 1.11022302463e-16, 1, 4.16333634234e-17, -3.9, -0.1 };
static const double aspect_coefficients_array_35[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1.11022302463e-16, 0, 1, 0, 0, 0, 0, -3.45, 4, 0, 0, 0, -1.11022302463e-16, 0, -1, 3.9, -4.16333634234e-17, 0.1 };
static const double aspect_coefficients_array_36[] = {
	0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -0, 0, 0, 0, 0, 1, 0, 0, 0, 0, -0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0 };
static const double aspect_coefficients_array_37[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, -0, 7.8, 0, 0.2, 0, 0, 0, 0, 0, -1, 0, 10, -4 };
static const double aspect_coefficients_array_38[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, -5.55111512313e-17, 6.93889390391e-18, 0, 0, 0, -5, 3.9, 3.6, 5.55111512313e-17, -6.93889390391e-18, 0, 0, 0, 0, 0, -1, 3.9, 1.38777878078e-17, -1.38777878078e-17, 0.1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, 5.55111512313e-17, -6.93889390391e-18, 0, -0, 0, -5, 3.9, 3.6, 5.55111512313e-17, -6.93889390391e-18, 0, 0, 0, 0, 0, 1, 3.9, 1.38777878078e-17, -1.38777878078e-17, 0.1 };
static const double aspect_coefficients_array_39[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -0, 0, 0, -1, 0, 0, 1, 0, 0, -1, 0, 0, 0, 7.8, 0, 0.2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, -7.8, 0, -0.2, 0, 0, 0, 0, 0, -1, 0, 0, 1 };
static const double aspect_coefficients_array_40[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 10, 0, -5, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 10, -5, 0, 0, 0, -1, 0, 0, 0, 0, -2.22044604925e-15, 10, -2.22044604925e-15, -4, 0, 0, 0, 0, 0, 0, 0, 1, -10, 0, -10, 10, 0, 0, 0, 1, 0, 0, 0, 0, 1.7763568394e-15, 1.7763568394e-15, 1.7763568394e-15, -1, 0, 0, 0, -0, 0, 0, 0, -1, -10, 1.7763568394e-15, 0, 5 };
static const double aspect_coefficients_array_41[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -2.22044604925e-16, -1, 0, -0, 2.22044604925e-16, 2, 0, 0, -2.22044604925e-16, -1, 1.38777878078e-17, -1.38777878078e-17, 0, -1, 0, 0, 0, 1, 0, 0, 0, 1, -3.9, -0.1, 2.22044604925e-16, 1, 0, 0, 0, 1, 0, -0, -2.22044604925e-16, -1, 3.9, 0.1 };
static const double aspect_coefficients_array_42[] = {
	0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 5, 0, 0, -2, 0, 0, 0, 0, 0, 0, 0, -1, 0, -3.9, 0, -0.1, 0, 0, 3.33066907388e-16, 1, 0, 0, 0, 0, 0, 0, 0, 0.5, 0, 0, 0, 0, 0, 0, -3.33066907388e-16, -1, 0, 0, 3.9, 0.1, 0, 0, -3.33066907388e-16, -1, 0, 0, 0, -0, 5, 0, 0, -2.5, 0, 0, 0, 0, 0, 0, 3.33066907388e-16, 1, 0, -3.9, -3.9, -0.2 };
static const double aspect_coefficients_array_43[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1.11022302463e-16, -1.11022302463e-16, -1, 4.16333634234e-17, 1.38777878078e-17, -1.38777878078e-17, 3.9, -1.38777878078e-17, 0.1, -4.16333634234e-17, -1.38777878078e-17, 1.38777878078e-17, -1.11022302463e-16, -1.11022302463e-16, -1, 2.22044604925e-16, 3.9, 1.1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1.11022302463e-16, 3.33066907388e-16, 1, 4.16333634234e-17, 1.38777878078e-17, -1.38777878078e-17, -3.9, -4.16333634234e-17, -0.1, 4.16333634234e-17, 1.38777878078e-17, -1.38777878078e-17, -1.11022302463e-16, -3.33066907388e-16, -1, 0, 3.9, 1.1 };
static const double aspect_coefficients_array_44[] = {
	1, 0, 0, 0, 1, 0, 0, 1, 0, -1, 0, 2, -1, 0, 2, -0, -1, 2, -0, -1, 2, 1, 0, 0 };
static const double aspect_coefficients_array_45[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 5.55111512313e-17, 0, 0, 1, 0, 0, 0, -1, 5.55111512313e-17, 0, 0, 2, 0, -1, 1.11022302463e-16, 0, 0, 2, -1.11022302463e-16, -0, 0, -1, 0, 2, -1.66533453694e-16, -0, 0, -1, 0, 2, 0, 1, -1.66533453694e-16, -0, 0, 0, 6.66133814775e-16, 1, 3.69778549322e-32, 5.55111512313e-17, -1.38777878078e-17, -1.11022302463e-16, 3.69778549322e-32, 5.55111512313e-17, -6.66133814775e-16, -1, 1.33226762955e-15, 4, -5.55111512313e-17, 0, 6.66133814775e-16, 1, 0, 0, 6.66133814775e-16, 1, 5.55111512313e-17, 0, 0, 2, -6.66133814775e-16, -1, 0, 0, 1.33226762955e-15, 2, 0, 0, 6.66133814775e-16, 1, 0, 2, -5.55111512313e-17, -0, -6.66133814775e-16, -1, 1.33226762955e-15, 2, -6.66133814775e-16, -1, 5.55111512313e-17, 0, 1.33226762955e-15, 4 };
static const double aspect_coefficients_array_46[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3.33066907388e-16, 1, 0, 0, 3.8, 0.1, 0, 0, -3.33066907388e-16, -1, -3.8, 0.9 };
static const double aspect_coefficients_array_47[] = {
	1, 0, 0, 0, 1, 0, 0, -1, 2, 1, 0, 0 };
static const double aspect_coefficients_array_48[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };
static const double aspect_coefficients_array_49[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -1.11022302463e-16, -1, 0, -0, 0, 2, 0, 0, -1.11022302463e-16, -1, 3.9, 0.1 };
static const double aspect_coefficients_array_50[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1.11022302463e-16, -1, 0, 2.77555756156e-17, 0, 0, -3.45, 5, 0, -2.77555756156e-17, 0, 0, 1.11022302463e-16, -1, 3.9, 1.38777878078e-17, 0.1 };
static const double aspect_coefficients_array_51[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 5, 0, -1, 0, 0, 0, 0, 0, -1, 0, -3.9, -0.1 };
static const double aspect_coefficients_array_52[] = {
	1, 0, 0, 0, 1, 0, 0, -1, 2, 1, 0, 0, -1, -0, 2, 0, -1, 2, -0, 1, 0, -1, -0, 2 };
static const double aspect_coefficients_array_53[] = {
	1, 0, 0, 0, 1, 0, 0.5, 0.866025403784, -0.866025403784, -0.866025403784, 0.5, 0.5, -0.5, 0.866025403784, -0.866025403784, -0.866025403784, -0.5, 1.5, -1, 1.11022302463e-16, -1.11022302463e-16, -1.11022302463e-16, -1, 2, -0.5, -0.866025403784, 0.866025403784, 0.866025403784, -0.5, 1.5, 0.5, -0.866025403784, 0.866025403784, 0.866025403784, 0.5, 0.5, -1, 0, 0, 0, 1, 0, -0.5, 0.866025403784, -0.866025403784, 0.866025403784, 0.5, 0.5, 0.5, 0.866025403784, -0.866025403784, 0.866025403784, -0.5, 1.5, 1, 1.11022302463e-16, -1.11022302463e-16, 1.11022302463e-16, -1, 2, 0.5, -0.866025403784, 0.866025403784, -0.866025403784, -0.5, 1.5, -0.5, -0.866025403784, 0.866025403784, -0.866025403784, 0.5, 0.5 };
static const double aspect_coefficients_array_54[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 1, 0, 0, 0, -1, 3.9, 0.1, -2.22044604925e-16, -1, 0, 0, 2.22044604925e-16, 2, 0, 0, 2.22044604925e-16, 1, -2.77555756156e-17, 2.77555756156e-17, 2.22044604925e-16, 1, 0, 0, 0, 1, 0, -0, -2.22044604925e-16, -1, 3.9, 0.1 };
static const double aspect_coefficients_array_55[] = {
	1, 0, 0, 0, 1, 0, 0, 1, 0, -1, 0, 1, -1, 0, 1, -0, -1, 1, -0, -1, 1, 1, -0, 0 };
static const double aspect_coefficients_array_56[] = {
	1, 0, 0, 0, 1, 0, 0, 1, 0, -1, 0, 1, -1, 0, 1, -0, -1, 1, -0, -1, 1, 1, -0, 0, -1, 0, 0, 0, 1, 0, 0, -1, 0, -1, -0, 1, 1, 0, -1, 0, -1, 1, 0, 1, -1, 1, 0, 0 };
static const double aspect_coefficients_array_57[] = {
	1, 0, 0, 0, 1, 0, 0, -1, 1, 1, 0, 0, -1, -0, 1, 0, -1, 1, -0, 1, 0, -1, -0, 1 };
static const double aspect_coefficients_array_58[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0 };
static const double aspect_coefficients_array_59[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, -0, 0, 0, 1, 0, 0, -0, 0, 0, -1, 0, 0, 0 };
static const double aspect_coefficients_array_60[] = {
	0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 5, 0, -1, 0, 0, 0, 0, 0, -1, -2.77555756156e-17, 3.9, 0.1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -5.55111512313e-17, 7.8, 0.2, 0, 0, -1, 0, 0, -0, 5, 0, -1, 0, 0, 0, 0, 0, 1, -2.77555756156e-17, 3.9, 0.1 };
static const double aspect_coefficients_array_61[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, -6.66133814775e-16, -1, 0, 0, 0, 1, 0, 0, -6.66133814775e-16, -1, 7.8, 0.2, 3.33066907388e-16, 1, 0, 0, 0, 0.5, 0, 0, -3.33066907388e-16, -1, 3.9, 0.1, -3.33066907388e-16, -1, 0, -0, 2.22044604925e-16, 1.5, 0, 0, 3.33066907388e-16, 1, 3.9, 0.1 };
static const double aspect_coefficients_array_62[] = {
	1, 0, 0, 0, 1, 0, 0.5, -0.866025403784, 0.5, 0.866025403784, 0.5, 0.866025403784, -0.5, -0.866025403784, -2.22044604925e-16, 0.866025403784, -0.5, 1.73205080757, -1, 2.77555756156e-16, -1, -2.77555756156e-16, -1, 1.73205080757, -0.5, 0.866025403784, -1.5, -0.866025403784, -0.5, 0.866025403784, 0.5, 0.866025403784, -1, -0.866025403784, 0.5, -7.77156117238e-16 };
static const double aspect_coefficients_array_63[] = {
	1, 0, 0, 0, 1, 0, -1, 0, 0.5, 0, -1, 0.866025403784 };
static const double aspect_coefficients_array_64[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, -0, 0, 1, 0, -0, 0, -1, 0, 0 };

static const U8 colouring_array_00[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 0, 1, 3 };
static const U8 colouring_array_01[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 1, 2, 3 };
static const U8 colouring_array_02[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 2, 0, 1, 3 };
static const U8 colouring_array_03[] = {
	0, 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 2, 0, 1, 3 };
static const U8 colouring_array_04[] = {
	0, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 1, 2, 3 };
static const U8 colouring_array_05[] = {
	0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 2, 3 };
static const U8 colouring_array_06[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 1, 2, 3 };
static const U8 colouring_array_07[] = {
	0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 0, 1, 3 };
static const U8 colouring_array_08[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 0, 1, 3 };
static const U8 colouring_array_09[] = {
	0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1, 2, 0, 3 };
static const U8 colouring_array_10[] = {
	0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1, 0, 1, 2, 3 };
static const U8 colouring_array_11[] = {
	0, 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 2, 0, 3 };
static const U8 colouring_array_12[] = {
	0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 0, 1, 2, 3 };
static const U8 colouring_array_13[] = {
	0, 1, 2, 1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 0, 1, 3 };
static const U8 colouring_array_14[] = {
	0, 1, 2, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 2, 3 };
static const U8 colouring_array_15[] = {
	0, 2, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 0, 1, 3 };
static const U8 colouring_array_16[] = {
	0, 2, 1, 0, 1, 2, 0, 0, 0, 0, 0, 0, 2, 0, 1, 1, 2, 0, 3 };
static const U8 colouring_array_17[] = {
	1, 0, 2, 2, 0, 1, 0, 0, 0, 0, 0, 0, 1, 2, 0, 2, 0, 1, 3 };
static const U8 colouring_array_18[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 1, 0, 2, 2 };
static const U8 colouring_array_19[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 0, 1, 2, 2 };
static const U8 colouring_array_20[] = {
	0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 2, 2 };
static const U8 colouring_array_21[] = {
	0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 2, 2 };
static const U8 colouring_array_22[] = {
	0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 2, 2 };
static const U8 colouring_array_23[] = {
	0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 2, 2 };
static const U8 colouring_array_24[] = {
	0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 2, 2 };
static const U8 colouring_array_25[] = {
	0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 2, 2 };
static const U8 colouring_array_26[] = {
	0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 2, 0, 1, 2, 2 };
static const U8 colouring_array_27[] = {
	0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 2, 1, 0, 2, 2 };
static const U8 colouring_array_28[] = {
	0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 2, 0, 1, 2, 2 };

static const TilingTypeData tiling_type_data[94] = {
	// IH00 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH01
	{
		4, 1, 6, 3,
		edge_shapes_array_00,
		edge_orientations_array_00,
		edge_shape_ids_array_00,
		default_params_array_00,
		tiling_vertex_coefficients_array_00,
		translation_coefficients_array_00,
		aspect_coefficients_array_00,
		colouring_array_00
	},

	// IH02
	{
		4, 2, 6, 3,
		edge_shapes_array_00,
		edge_orientations_array_01,
		edge_shape_ids_array_01,
		default_params_array_01,
		tiling_vertex_coefficients_array_01,
		translation_coefficients_array_01,
		aspect_coefficients_array_01,
		colouring_array_01
	},

	// IH03
	{
		4, 2, 6, 3,
		edge_shapes_array_00,
		edge_orientations_array_02,
		edge_shape_ids_array_02,
		default_params_array_02,
		tiling_vertex_coefficients_array_02,
		translation_coefficients_array_02,
		aspect_coefficients_array_02,
		colouring_array_02
	},

	// IH04
	{
		6, 2, 6, 5,
		edge_shapes_array_01,
		edge_orientations_array_03,
		edge_shape_ids_array_03,
		default_params_array_03,
		tiling_vertex_coefficients_array_03,
		translation_coefficients_array_03,
		aspect_coefficients_array_03,
		colouring_array_02
	},

	// IH05
	{
		5, 4, 6, 4,
		edge_shapes_array_02,
		edge_orientations_array_04,
		edge_shape_ids_array_04,
		default_params_array_04,
		tiling_vertex_coefficients_array_04,
		translation_coefficients_array_04,
		aspect_coefficients_array_04,
		colouring_array_03
	},

	// IH06
	{
		5, 4, 6, 4,
		edge_shapes_array_03,
		edge_orientations_array_05,
		edge_shape_ids_array_05,
		default_params_array_05,
		tiling_vertex_coefficients_array_05,
		translation_coefficients_array_05,
		aspect_coefficients_array_05,
		colouring_array_04
	},

	// IH07
	{
		2, 3, 6, 3,
		edge_shapes_array_00,
		edge_orientations_array_06,
		edge_shape_ids_array_06,
		default_params_array_06,
		tiling_vertex_coefficients_array_06,
		translation_coefficients_array_06,
		aspect_coefficients_array_06,
		colouring_array_05
	},

	// IH08
	{
		4, 1, 6, 3,
		edge_shapes_array_04,
		edge_orientations_array_07,
		edge_shape_ids_array_00,
		default_params_array_00,
		tiling_vertex_coefficients_array_00,
		translation_coefficients_array_00,
		aspect_coefficients_array_00,
		colouring_array_00
	},

	// IH09
	{
		3, 2, 6, 2,
		edge_shapes_array_05,
		edge_orientations_array_08,
		edge_shape_ids_array_07,
		default_params_array_07,
		tiling_vertex_coefficients_array_07,
		translation_coefficients_array_07,
		aspect_coefficients_array_07,
		colouring_array_06
	},

	// IH10
	{
		0, 1, 6, 1,
		edge_shapes_array_06,
		edge_orientations_array_06,
		edge_shape_ids_array_08,
		default_params_array_08,
		tiling_vertex_coefficients_array_08,
		translation_coefficients_array_08,
		aspect_coefficients_array_08,
		colouring_array_00
	},

	// IH11
	{
		0, 1, 6, 1,
		edge_shapes_array_07,
		edge_orientations_array_07,
		edge_shape_ids_array_08,
		default_params_array_08,
		tiling_vertex_coefficients_array_08,
		translation_coefficients_array_09,
		aspect_coefficients_array_08,
		colouring_array_00
	},

	// IH12
	{
		2, 1, 6, 2,
		edge_shapes_array_08,
		edge_orientations_array_09,
		edge_shape_ids_array_07,
		default_params_array_09,
		tiling_vertex_coefficients_array_09,
		translation_coefficients_array_10,
		aspect_coefficients_array_09,
		colouring_array_00
	},

	// IH13
	{
		3, 2, 6, 3,
		edge_shapes_array_09,
		edge_orientations_array_10,
		edge_shape_ids_array_09,
		default_params_array_10,
		tiling_vertex_coefficients_array_10,
		translation_coefficients_array_11,
		aspect_coefficients_array_10,
		colouring_array_06
	},

	// IH14
	{
		2, 1, 6, 2,
		edge_shapes_array_10,
		edge_orientations_array_11,
		edge_shape_ids_array_10,
		default_params_array_09,
		tiling_vertex_coefficients_array_11,
		translation_coefficients_array_12,
		aspect_coefficients_array_09,
		colouring_array_00
	},

	// IH15
	{
		3, 2, 6, 3,
		edge_shapes_array_11,
		edge_orientations_array_12,
		edge_shape_ids_array_11,
		default_params_array_11,
		tiling_vertex_coefficients_array_12,
		translation_coefficients_array_13,
		aspect_coefficients_array_11,
		colouring_array_06
	},

	// IH16
	{
		1, 3, 6, 2,
		edge_shapes_array_12,
		edge_orientations_array_13,
		edge_shape_ids_array_12,
		default_params_array_12,
		tiling_vertex_coefficients_array_13,
		translation_coefficients_array_14,
		aspect_coefficients_array_12,
		colouring_array_05
	},

	// IH17
	{
		2, 1, 6, 2,
		edge_shapes_array_13,
		edge_orientations_array_14,
		edge_shape_ids_array_07,
		default_params_array_09,
		tiling_vertex_coefficients_array_09,
		translation_coefficients_array_10,
		aspect_coefficients_array_09,
		colouring_array_00
	},

	// IH18
	{
		0, 1, 6, 1,
		edge_shapes_array_14,
		edge_orientations_array_06,
		edge_shape_ids_array_08,
		default_params_array_08,
		tiling_vertex_coefficients_array_08,
		translation_coefficients_array_09,
		aspect_coefficients_array_08,
		colouring_array_00
	},

	// IH19 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH20
	{
		0, 1, 6, 1,
		edge_shapes_array_15,
		edge_orientations_array_07,
		edge_shape_ids_array_08,
		default_params_array_08,
		tiling_vertex_coefficients_array_08,
		translation_coefficients_array_09,
		aspect_coefficients_array_08,
		colouring_array_00
	},

	// IH21
	{
		2, 6, 5, 3,
		edge_shapes_array_16,
		edge_orientations_array_15,
		edge_shape_ids_array_13,
		default_params_array_13,
		tiling_vertex_coefficients_array_14,
		translation_coefficients_array_15,
		aspect_coefficients_array_13,
		colouring_array_07
	},

	// IH22
	{
		3, 2, 5, 3,
		edge_shapes_array_17,
		edge_orientations_array_16,
		edge_shape_ids_array_14,
		default_params_array_14,
		tiling_vertex_coefficients_array_15,
		translation_coefficients_array_16,
		aspect_coefficients_array_14,
		colouring_array_06
	},

	// IH23
	{
		4, 2, 5, 4,
		edge_shapes_array_18,
		edge_orientations_array_17,
		edge_shape_ids_array_15,
		default_params_array_15,
		tiling_vertex_coefficients_array_16,
		translation_coefficients_array_17,
		aspect_coefficients_array_15,
		colouring_array_08
	},

	// IH24
	{
		4, 4, 5, 4,
		edge_shapes_array_19,
		edge_orientations_array_17,
		edge_shape_ids_array_15,
		default_params_array_15,
		tiling_vertex_coefficients_array_16,
		translation_coefficients_array_18,
		aspect_coefficients_array_16,
		colouring_array_09
	},

	// IH25
	{
		3, 4, 5, 3,
		edge_shapes_array_20,
		edge_orientations_array_16,
		edge_shape_ids_array_14,
		default_params_array_14,
		tiling_vertex_coefficients_array_15,
		translation_coefficients_array_19,
		aspect_coefficients_array_17,
		colouring_array_10
	},

	// IH26
	{
		2, 2, 5, 3,
		edge_shapes_array_21,
		edge_orientations_array_18,
		edge_shape_ids_array_14,
		default_params_array_16,
		tiling_vertex_coefficients_array_17,
		translation_coefficients_array_20,
		aspect_coefficients_array_18,
		colouring_array_01
	},

	// IH27
	{
		3, 4, 5, 3,
		edge_shapes_array_16,
		edge_orientations_array_19,
		edge_shape_ids_array_16,
		default_params_array_17,
		tiling_vertex_coefficients_array_18,
		translation_coefficients_array_21,
		aspect_coefficients_array_19,
		colouring_array_11
	},

	// IH28
	{
		2, 4, 5, 3,
		edge_shapes_array_16,
		edge_orientations_array_15,
		edge_shape_ids_array_13,
		default_params_array_18,
		tiling_vertex_coefficients_array_19,
		translation_coefficients_array_22,
		aspect_coefficients_array_20,
		colouring_array_12
	},

	// IH29
	{
		1, 4, 5, 2,
		edge_shapes_array_12,
		edge_orientations_array_20,
		edge_shape_ids_array_17,
		default_params_array_19,
		tiling_vertex_coefficients_array_20,
		translation_coefficients_array_23,
		aspect_coefficients_array_21,
		colouring_array_04
	},

	// IH30
	{
		1, 6, 4, 3,
		edge_shapes_array_22,
		edge_orientations_array_21,
		edge_shape_ids_array_18,
		default_params_array_20,
		tiling_vertex_coefficients_array_21,
		translation_coefficients_array_24,
		aspect_coefficients_array_22,
		colouring_array_13
	},

	// IH31
	{
		0, 6, 4, 2,
		edge_shapes_array_23,
		edge_orientations_array_22,
		edge_shape_ids_array_19,
		default_params_array_08,
		tiling_vertex_coefficients_array_22,
		translation_coefficients_array_25,
		aspect_coefficients_array_23,
		colouring_array_14
	},

	// IH32
	{
		0, 6, 4, 2,
		edge_shapes_array_24,
		edge_orientations_array_23,
		edge_shape_ids_array_19,
		default_params_array_08,
		tiling_vertex_coefficients_array_22,
		translation_coefficients_array_26,
		aspect_coefficients_array_24,
		colouring_array_15
	},

	// IH33
	{
		0, 3, 4, 2,
		edge_shapes_array_23,
		edge_orientations_array_22,
		edge_shape_ids_array_19,
		default_params_array_08,
		tiling_vertex_coefficients_array_23,
		translation_coefficients_array_08,
		aspect_coefficients_array_25,
		colouring_array_05
	},

	// IH34
	{
		0, 3, 4, 1,
		edge_shapes_array_06,
		edge_orientations_array_24,
		edge_shape_ids_array_20,
		default_params_array_08,
		tiling_vertex_coefficients_array_23,
		translation_coefficients_array_09,
		aspect_coefficients_array_26,
		colouring_array_05
	},

	// IH35 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH36
	{
		0, 3, 4, 1,
		edge_shapes_array_06,
		edge_orientations_array_25,
		edge_shape_ids_array_20,
		default_params_array_08,
		tiling_vertex_coefficients_array_23,
		translation_coefficients_array_08,
		aspect_coefficients_array_27,
		colouring_array_05
	},

	// IH37
	{
		0, 3, 4, 1,
		edge_shapes_array_15,
		edge_orientations_array_26,
		edge_shape_ids_array_20,
		default_params_array_08,
		tiling_vertex_coefficients_array_23,
		translation_coefficients_array_08,
		aspect_coefficients_array_28,
		colouring_array_05
	},

	// IH38
	{
		0, 6, 3, 2,
		edge_shapes_array_10,
		edge_orientations_array_27,
		edge_shape_ids_array_21,
		default_params_array_08,
		tiling_vertex_coefficients_array_24,
		translation_coefficients_array_27,
		aspect_coefficients_array_29,
		colouring_array_15
	},

	// IH39
	{
		0, 6, 3, 2,
		edge_shapes_array_25,
		edge_orientations_array_27,
		edge_shape_ids_array_21,
		default_params_array_08,
		tiling_vertex_coefficients_array_24,
		translation_coefficients_array_28,
		aspect_coefficients_array_30,
		colouring_array_16
	},

	// IH40
	{
		0, 6, 3, 2,
		edge_shapes_array_24,
		edge_orientations_array_28,
		edge_shape_ids_array_21,
		default_params_array_08,
		tiling_vertex_coefficients_array_24,
		translation_coefficients_array_29,
		aspect_coefficients_array_31,
		colouring_array_17
	},

	// IH41
	{
		2, 1, 4, 2,
		edge_shapes_array_23,
		edge_orientations_array_22,
		edge_shape_ids_array_22,
		default_params_array_21,
		tiling_vertex_coefficients_array_25,
		translation_coefficients_array_30,
		aspect_coefficients_array_09,
		colouring_array_18
	},

	// IH42
	{
		2, 2, 4, 3,
		edge_shapes_array_22,
		edge_orientations_array_29,
		edge_shape_ids_array_23,
		default_params_array_21,
		tiling_vertex_coefficients_array_25,
		translation_coefficients_array_31,
		aspect_coefficients_array_32,
		colouring_array_19
	},

	// IH43
	{
		2, 2, 4, 2,
		edge_shapes_array_23,
		edge_orientations_array_30,
		edge_shape_ids_array_22,
		default_params_array_21,
		tiling_vertex_coefficients_array_25,
		translation_coefficients_array_31,
		aspect_coefficients_array_33,
		colouring_array_19
	},

	// IH44
	{
		2, 2, 4, 2,
		edge_shapes_array_23,
		edge_orientations_array_31,
		edge_shape_ids_array_24,
		default_params_array_22,
		tiling_vertex_coefficients_array_26,
		translation_coefficients_array_32,
		aspect_coefficients_array_34,
		colouring_array_20
	},

	// IH45
	{
		2, 2, 4, 3,
		edge_shapes_array_22,
		edge_orientations_array_32,
		edge_shape_ids_array_23,
		default_params_array_23,
		tiling_vertex_coefficients_array_27,
		translation_coefficients_array_33,
		aspect_coefficients_array_35,
		colouring_array_20
	},

	// IH46
	{
		4, 2, 4, 4,
		edge_shapes_array_26,
		edge_orientations_array_33,
		edge_shape_ids_array_25,
		default_params_array_24,
		tiling_vertex_coefficients_array_28,
		translation_coefficients_array_34,
		aspect_coefficients_array_36,
		colouring_array_20
	},

	// IH47
	{
		2, 2, 4, 3,
		edge_shapes_array_27,
		edge_orientations_array_29,
		edge_shape_ids_array_23,
		default_params_array_21,
		tiling_vertex_coefficients_array_25,
		translation_coefficients_array_35,
		aspect_coefficients_array_37,
		colouring_array_19
	},

	// IH48 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH49
	{
		3, 4, 4, 4,
		edge_shapes_array_28,
		edge_orientations_array_33,
		edge_shape_ids_array_25,
		default_params_array_25,
		tiling_vertex_coefficients_array_29,
		translation_coefficients_array_36,
		aspect_coefficients_array_38,
		colouring_array_21
	},

	// IH50
	{
		2, 4, 4, 3,
		edge_shapes_array_29,
		edge_orientations_array_29,
		edge_shape_ids_array_23,
		default_params_array_21,
		tiling_vertex_coefficients_array_25,
		translation_coefficients_array_37,
		aspect_coefficients_array_39,
		colouring_array_22
	},

	// IH51
	{
		3, 4, 4, 3,
		edge_shapes_array_27,
		edge_orientations_array_32,
		edge_shape_ids_array_23,
		default_params_array_26,
		tiling_vertex_coefficients_array_30,
		translation_coefficients_array_38,
		aspect_coefficients_array_40,
		colouring_array_21
	},

	// IH52
	{
		1, 4, 4, 2,
		edge_shapes_array_23,
		edge_orientations_array_34,
		edge_shape_ids_array_22,
		default_params_array_20,
		tiling_vertex_coefficients_array_31,
		translation_coefficients_array_39,
		aspect_coefficients_array_41,
		colouring_array_23
	},

	// IH53
	{
		3, 4, 4, 3,
		edge_shapes_array_27,
		edge_orientations_array_35,
		edge_shape_ids_array_26,
		default_params_array_27,
		tiling_vertex_coefficients_array_32,
		translation_coefficients_array_40,
		aspect_coefficients_array_42,
		colouring_array_21
	},

	// IH54
	{
		2, 4, 4, 4,
		edge_shapes_array_30,
		edge_orientations_array_33,
		edge_shape_ids_array_25,
		default_params_array_28,
		tiling_vertex_coefficients_array_33,
		translation_coefficients_array_41,
		aspect_coefficients_array_43,
		colouring_array_22
	},

	// IH55
	{
		0, 4, 4, 2,
		edge_shapes_array_23,
		edge_orientations_array_24,
		edge_shape_ids_array_24,
		default_params_array_08,
		tiling_vertex_coefficients_array_34,
		translation_coefficients_array_42,
		aspect_coefficients_array_44,
		colouring_array_24
	},

	// IH56
	{
		1, 8, 4, 3,
		edge_shapes_array_22,
		edge_orientations_array_36,
		edge_shape_ids_array_26,
		default_params_array_29,
		tiling_vertex_coefficients_array_35,
		translation_coefficients_array_43,
		aspect_coefficients_array_45,
		colouring_array_25
	},

	// IH57
	{
		2, 1, 4, 2,
		edge_shapes_array_31,
		edge_orientations_array_33,
		edge_shape_ids_array_22,
		default_params_array_21,
		tiling_vertex_coefficients_array_25,
		translation_coefficients_array_30,
		aspect_coefficients_array_09,
		colouring_array_18
	},

	// IH58
	{
		2, 2, 4, 2,
		edge_shapes_array_32,
		edge_orientations_array_33,
		edge_shape_ids_array_22,
		default_params_array_21,
		tiling_vertex_coefficients_array_25,
		translation_coefficients_array_31,
		aspect_coefficients_array_32,
		colouring_array_19
	},

	// IH59
	{
		1, 2, 4, 1,
		edge_shapes_array_06,
		edge_orientations_array_31,
		edge_shape_ids_array_20,
		default_params_array_30,
		tiling_vertex_coefficients_array_36,
		translation_coefficients_array_44,
		aspect_coefficients_array_46,
		colouring_array_20
	},

	// IH60 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH61
	{
		0, 2, 4, 1,
		edge_shapes_array_06,
		edge_orientations_array_24,
		edge_shape_ids_array_20,
		default_params_array_08,
		tiling_vertex_coefficients_array_34,
		translation_coefficients_array_45,
		aspect_coefficients_array_47,
		colouring_array_20
	},

	// IH62
	{
		0, 1, 4, 1,
		edge_shapes_array_07,
		edge_orientations_array_33,
		edge_shape_ids_array_20,
		default_params_array_08,
		tiling_vertex_coefficients_array_34,
		translation_coefficients_array_46,
		aspect_coefficients_array_08,
		colouring_array_18
	},

	// IH63 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH64
	{
		1, 1, 4, 2,
		edge_shapes_array_33,
		edge_orientations_array_37,
		edge_shape_ids_array_22,
		default_params_array_20,
		tiling_vertex_coefficients_array_31,
		translation_coefficients_array_47,
		aspect_coefficients_array_48,
		colouring_array_18
	},

	// IH65 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH66
	{
		1, 2, 4, 2,
		edge_shapes_array_34,
		edge_orientations_array_37,
		edge_shape_ids_array_22,
		default_params_array_20,
		tiling_vertex_coefficients_array_31,
		translation_coefficients_array_48,
		aspect_coefficients_array_49,
		colouring_array_19
	},

	// IH67
	{
		2, 2, 4, 3,
		edge_shapes_array_21,
		edge_orientations_array_38,
		edge_shape_ids_array_23,
		default_params_array_23,
		tiling_vertex_coefficients_array_27,
		translation_coefficients_array_49,
		aspect_coefficients_array_50,
		colouring_array_20
	},

	// IH68
	{
		1, 1, 4, 1,
		edge_shapes_array_06,
		edge_orientations_array_39,
		edge_shape_ids_array_20,
		default_params_array_30,
		tiling_vertex_coefficients_array_36,
		translation_coefficients_array_50,
		aspect_coefficients_array_48,
		colouring_array_18
	},

	// IH69
	{
		2, 2, 4, 2,
		edge_shapes_array_31,
		edge_orientations_array_26,
		edge_shape_ids_array_24,
		default_params_array_22,
		tiling_vertex_coefficients_array_26,
		translation_coefficients_array_32,
		aspect_coefficients_array_51,
		colouring_array_20
	},

	// IH70 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH71
	{
		0, 4, 4, 1,
		edge_shapes_array_06,
		edge_orientations_array_40,
		edge_shape_ids_array_20,
		default_params_array_08,
		tiling_vertex_coefficients_array_34,
		translation_coefficients_array_42,
		aspect_coefficients_array_52,
		colouring_array_24
	},

	// IH72
	{
		1, 1, 4, 2,
		edge_shapes_array_24,
		edge_orientations_array_33,
		edge_shape_ids_array_22,
		default_params_array_20,
		tiling_vertex_coefficients_array_31,
		translation_coefficients_array_47,
		aspect_coefficients_array_48,
		colouring_array_18
	},

	// IH73
	{
		0, 2, 4, 1,
		edge_shapes_array_14,
		edge_orientations_array_24,
		edge_shape_ids_array_20,
		default_params_array_08,
		tiling_vertex_coefficients_array_34,
		translation_coefficients_array_45,
		aspect_coefficients_array_47,
		colouring_array_20
	},

	// IH74
	{
		1, 1, 4, 1,
		edge_shapes_array_07,
		edge_orientations_array_26,
		edge_shape_ids_array_20,
		default_params_array_30,
		tiling_vertex_coefficients_array_36,
		translation_coefficients_array_50,
		aspect_coefficients_array_48,
		colouring_array_18
	},

	// IH75 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH76
	{
		0, 1, 4, 1,
		edge_shapes_array_15,
		edge_orientations_array_33,
		edge_shape_ids_array_20,
		default_params_array_08,
		tiling_vertex_coefficients_array_34,
		translation_coefficients_array_46,
		aspect_coefficients_array_08,
		colouring_array_18
	},

	// IH77
	{
		0, 12, 3, 3,
		edge_shapes_array_35,
		edge_orientations_array_41,
		edge_shape_ids_array_27,
		default_params_array_08,
		tiling_vertex_coefficients_array_37,
		translation_coefficients_array_51,
		aspect_coefficients_array_53,
		colouring_array_26
	},

	// IH78
	{
		1, 4, 3, 3,
		edge_shapes_array_36,
		edge_orientations_array_41,
		edge_shape_ids_array_27,
		default_params_array_20,
		tiling_vertex_coefficients_array_38,
		translation_coefficients_array_52,
		aspect_coefficients_array_54,
		colouring_array_22
	},

	// IH79
	{
		0, 4, 3, 2,
		edge_shapes_array_25,
		edge_orientations_array_27,
		edge_shape_ids_array_21,
		default_params_array_08,
		tiling_vertex_coefficients_array_39,
		translation_coefficients_array_53,
		aspect_coefficients_array_55,
		colouring_array_27
	},

	// IH80 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH81
	{
		0, 8, 3, 2,
		edge_shapes_array_10,
		edge_orientations_array_27,
		edge_shape_ids_array_21,
		default_params_array_08,
		tiling_vertex_coefficients_array_39,
		translation_coefficients_array_54,
		aspect_coefficients_array_56,
		colouring_array_25
	},

	// IH82
	{
		0, 4, 3, 2,
		edge_shapes_array_24,
		edge_orientations_array_28,
		edge_shape_ids_array_21,
		default_params_array_08,
		tiling_vertex_coefficients_array_39,
		translation_coefficients_array_55,
		aspect_coefficients_array_57,
		colouring_array_27
	},

	// IH83
	{
		1, 2, 3, 2,
		edge_shapes_array_10,
		edge_orientations_array_42,
		edge_shape_ids_array_28,
		default_params_array_31,
		tiling_vertex_coefficients_array_40,
		translation_coefficients_array_56,
		aspect_coefficients_array_58,
		colouring_array_20
	},

	// IH84
	{
		2, 2, 3, 3,
		edge_shapes_array_04,
		edge_orientations_array_41,
		edge_shape_ids_array_27,
		default_params_array_32,
		tiling_vertex_coefficients_array_41,
		translation_coefficients_array_57,
		aspect_coefficients_array_59,
		colouring_array_20
	},

	// IH85
	{
		2, 4, 3, 3,
		edge_shapes_array_37,
		edge_orientations_array_41,
		edge_shape_ids_array_27,
		default_params_array_32,
		tiling_vertex_coefficients_array_41,
		translation_coefficients_array_58,
		aspect_coefficients_array_60,
		colouring_array_21
	},

	// IH86
	{
		1, 4, 3, 2,
		edge_shapes_array_25,
		edge_orientations_array_42,
		edge_shape_ids_array_28,
		default_params_array_31,
		tiling_vertex_coefficients_array_40,
		translation_coefficients_array_59,
		aspect_coefficients_array_61,
		colouring_array_21
	},

	// IH87 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH88
	{
		0, 6, 3, 2,
		edge_shapes_array_25,
		edge_orientations_array_43,
		edge_shape_ids_array_28,
		default_params_array_08,
		tiling_vertex_coefficients_array_42,
		translation_coefficients_array_60,
		aspect_coefficients_array_62,
		colouring_array_28
	},

	// IH89 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH90
	{
		0, 2, 3, 1,
		edge_shapes_array_07,
		edge_orientations_array_41,
		edge_shape_ids_array_29,
		default_params_array_08,
		tiling_vertex_coefficients_array_42,
		translation_coefficients_array_09,
		aspect_coefficients_array_63,
		colouring_array_20
	},

	// IH91
	{
		1, 2, 3, 2,
		edge_shapes_array_32,
		edge_orientations_array_44,
		edge_shape_ids_array_28,
		default_params_array_31,
		tiling_vertex_coefficients_array_40,
		translation_coefficients_array_61,
		aspect_coefficients_array_64,
		colouring_array_20
	},

	// IH92 is undefined
	{
		0, 0, 0, 0,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr
	},

	// IH93
	{
		0, 2, 3, 1,
		edge_shapes_array_15,
		edge_orientations_array_41,
		edge_shape_ids_array_29,
		default_params_array_08,
		tiling_vertex_coefficients_array_42,
		translation_coefficients_array_09,
		aspect_coefficients_array_63,
		colouring_array_20
	},

