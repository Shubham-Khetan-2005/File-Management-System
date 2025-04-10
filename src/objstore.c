/* objstore.c - Skeleton Implementation of the Object Store
 *
 * This file implements the core functionalities of the object store:
 *  - Initialization and cleanup of the object store.
 *  - Creation, reading, writing, deletion, and renaming of objects.
 *  - Optional cache support enabled with the -DCACHE flag.
 *
 * IMPORTANT:
 *  - Use dprintf (not printf) for logging. Remove these debug statements prior to final submission.
 *  - Do not modify any code or declarations outside this file.
 */

#include "lib.h" // Contains struct objfs_state and prototypes for read_block/write_block functions.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef DEBUG
#define dprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define dprintf(...)
#endif

/*
 * objstore_init: Initialize the object store when the filesystem is mounted.
 * You may allocate and set up necessary in-memory structures here.
 */
int objstore_init(struct objfs_state *objfs)
{
  dprintf("objstore_init: Initializing object store.\n");
  /* TODO: Allocate and initialize your in-memory structures.
   * For example:
   *     objfs->objstore_data = malloc(sizeof(your_data_structure));
   */
  return 0;
}

/*
 * objstore_destroy: Clean up the object store on unmount.
 * Free any allocated memory and perform the necessary cleanup.
 */
int objstore_destroy(struct objfs_state *objfs)
{
  dprintf("objstore_destroy: Cleaning up object store.\n");
  /* TODO: Clean up your in-memory data structures.
   * For example:
   *     free(objfs->objstore_data);
   *     objfs->objstore_data = NULL;
   */
  return 0;
}

/*
 * create_object: Create a new object with a unique key and data.
 * Object IDs 0 and 1 are reserved. This function should store data using write_block.
 */
int create_object(struct objfs_state *objfs, const char *key, const char *data, size_t data_size)
{
  dprintf("create_object: Creating object with key '%s', data size %zu bytes.\n", key, data_size);
  /* TODO:
   * - Reserve a unique object ID (starting from 2, since 0 and 1 are reserved).
   * - Write object data to the disk image using write_block.
   * - Update your in-memory data structure accordingly.
   */
  return 2; /* Placeholder: return the first valid object ID */
}

/*
 * read_object: Read the complete contents of an object into a provided buffer.
 * Even if buf_size is larger than the actual object size, return buf_size as required.
 */
ssize_t read_object(struct objfs_state *objfs, const char *key, char *buf, size_t buf_size)
{
  dprintf("read_object: Reading object with key '%s'.\n", key);
  /* TODO:
   * - Use read_block to retrieve data from the disk image.
   * - Copy the object data into buf.
   */
  return buf_size; /* Placeholder: assume successful read fills buf_size bytes */
}

/*
 * write_object: Overwrite the object data and update the stored size.
 * Uses write_block to update the disk image.
 */
ssize_t write_object(struct objfs_state *objfs, const char *key, const char *data, size_t data_size)
{
  dprintf("write_object: Writing object with key '%s', data size %zu bytes.\n", key, data_size);
  /* TODO:
   * - Overwrite the object's data.
   * - Update the metadata (e.g., object size) in your in-memory structure.
   */
  return data_size; /* Placeholder: assume successful write of data_size bytes */
}

/*
 * delete_object: Delete an object by removing it from in-memory structures and marking disk blocks as free.
 */
int delete_object(struct objfs_state *objfs, const char *key)
{
  dprintf("delete_object: Deleting object with key '%s'.\n", key);
  /* TODO:
   * - Remove the object from your in-memory data structure.
   * - Mark the associated disk blocks as free using your block management functions.
   */
  return 0;
}

/*
 * rename_object: Rename an existing object from old_key to new_key.
 * Update the in-memory data structure accordingly.
 */
int rename_object(struct objfs_state *objfs, const char *old_key, const char *new_key)
{
  dprintf("rename_object: Renaming object from '%s' to '%s'.\n", old_key, new_key);
  /* TODO: Update your in-memory structure to reflect the new key name. */
  return 0;
}

#ifdef DCACHE
/*
 * The following functions support caching functionality when compiled with -DCACHE.
 * The cache (128MB, 4KB aligned) is available via objfs->cache.
 */

int cache_lookup(struct objfs_state *objfs, const char *key, char *buf, size_t buf_size)
{
  dprintf("cache_lookup: Looking up cache for key '%s'.\n", key);
  /* TODO: Implement your caching lookup logic here. */
  return 0; /* Placeholder: return 0 on cache miss or size on hit */
}

int cache_update(struct objfs_state *objfs, const char *key, const char *data, size_t data_size)
{
  dprintf("cache_update: Updating cache for key '%s'.\n", key);
  /* TODO: Implement your caching update logic here. */
  return 0;
}
#endif
