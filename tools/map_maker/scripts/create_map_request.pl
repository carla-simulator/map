#!/usr/bin/perl
# ----------------- BEGIN LICENSE BLOCK ---------------------------------
#
# Copyright (C) 2017-2019 Intel Corporation
#
# SPDX-License-Identifier: MIT
#
# ----------------- END LICENSE BLOCK -----------------------------------

#
# Parse a give osm-file and print out a string that can be used with wget to download a $map
#
# Files to be checked is simply specified on the command-line, e.g. create_map_request <map_file>
#

use strict;
use warnings;

my $minlat;
my $minlon;
my $maxlat;
my $maxlon;

# gets a string of type something = 'number'
sub extractNumberFromTag {
  my $tag = shift;
  my ($result) = $tag =~ /.*\'(\d+\.\d+)'.*/;
  return $result;
}

while (my $filename = shift(@ARGV)) {
  open FILE, $filename;
  while (<FILE>) {
    if (/<bounds/) {
      my @tags = split(' ', $_);
      foreach my $tag (@tags) {
        if ($tag =~ m/minlat/g) {
          $minlat = extractNumberFromTag($tag);
        } elsif ($tag =~ m/minlon/g) {
          $minlon = extractNumberFromTag($tag);
        } elsif ($tag =~ m/maxlat/g) {
          $maxlat = extractNumberFromTag($tag);
        } elsif ($tag =~ m/maxlon/g) {
          $maxlon = extractNumberFromTag($tag);
       }
      }
      print "http://api.openstreetmap.org/api/0.6/map?bbox=$minlon,$minlat,$maxlon,$maxlat\n";
      exit;
    }
  }
}
