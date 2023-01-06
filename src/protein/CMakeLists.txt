add_library (protein inferring_mRna_from_protein.cc inferring_mRna_from_protein.h)

target_include_directories (protein PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
