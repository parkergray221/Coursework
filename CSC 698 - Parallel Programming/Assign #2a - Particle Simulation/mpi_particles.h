#ifndef __MPI_PARTICLES_H__
#define __MPI_PARTICLES_H__

#include <vector>
#include <mpi.h>

#define EMIGRANT_TAG    1
#define GHOST_TAG       2

extern MPI_Datatype PARTICLE;

//
// Functions to initialize emigrant buffers
//
void init_emigrant_buf(int n);
void free_emigrant_buf();

//
// Functions to initialize ghost buffers
//
void setup_ghost_structure(int max_particles);
void clean_ghost_structure();

//
// Functions to initialize each processor's set of particles at the beginning of the simulation, and to
// save all the particles at the end of the simulation.
//
int select_particles(int n, particle_t* particles, particle_t* local, char* p_valid, double left_x, double right_x, double bottom_y, double top_y);
void prepare_save(int rank, int n_proc, particle_t* local, char* p_valid, int nlocal, particle_t* particles, int n);
bool compare_particles(particle_t left, particle_t right); // check if id < id

//
// Functions to send/receive emigrants
//
void prepare_emigrants(particle_t* particles, char* p_valid, int* num_particles, double left_x, double right_x, double bottom_y, double top_y, int* neighbors);
void send_emigrants(int* neighbors);
void receive_immigrants(int* neighbors, int num_neighbors, particle_t* particles, char* p_valid, int* num_particles, int array_sz, int buf_size);

//
// Functions to send/receive ghost particles
//
void prepare_ghost_packets(particle_t particles[], char p_valid[], int num_particles, double left_x, double  right_x, double bottom_y, double top_y, int neighbors[]);
void send_ghost_packets(int neighbors[]);
void receive_ghost_packets(int* num_ghost_particles, particle_t* ghost_particle, int* neighbors, int num_neighbors, int buf_size);

void compute_forces(particle_t local[], char p_valid[], int num_particles, particle_t ghosts[], int num_ghosts);

#endif